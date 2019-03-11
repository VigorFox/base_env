# Copyright 2018 The Chromium Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

import boot_data
import common
import logging
import remote_cmd
import sys
import time


_SHUTDOWN_CMD = ['dm', 'poweroff']
_ATTACH_MAX_RETRIES = 10
_ATTACH_RETRY_INTERVAL = 1


class _MapRemoteDataPathForPackage:
  """Callable object which remaps /data paths to their package-specific
     locations."""

  def __init__(self, package_name, package_version):
    self.data_path = '/data/r/sys/fuchsia.com:{0}:{1}#meta:{0}.cmx'.format(
        package_name, package_version)

  def __call__(self, path):
    if path[:5] == '/data':
      return self.data_path + path[5:]
    return path


class FuchsiaTargetException(Exception):
  def __init__(self, message):
    super(FuchsiaTargetException, self).__init__(message)


class Target(object):
  """Base class representing a Fuchsia deployment target."""

  def __init__(self, output_dir, target_cpu):
    self._output_dir = output_dir
    self._started = False
    self._dry_run = False
    self._target_cpu = target_cpu
    self._command_runner = None

  # Functions used by the Python context manager for teardown.
  def __enter__(self):
    return self
  def __exit__(self, exc_type, exc_val, exc_tb):
    return self

  def Start(self):
    """Handles the instantiation and connection process for the Fuchsia
    target instance."""

    pass

  def IsStarted(self):
    """Returns True if the Fuchsia target instance is ready to accept
    commands."""

    return self._started

  def IsNewInstance(self):
    """Returns True if the connected target instance is newly provisioned."""

    return True

  def GetCommandRunner(self):
    """Returns CommandRunner that can be used to execute commands on the
    target. Most clients should prefer RunCommandPiped() and RunCommand()."""

    self._AssertIsStarted()

    if self._command_runner == None:
      host, port = self._GetEndpoint()
      self._command_runner = \
          remote_cmd.CommandRunner(self._GetSshConfigPath(), host, port)

    return self._command_runner

  def RunCommandPiped(self, command, **kwargs):
    """Starts a remote command and immediately returns a Popen object for the
    command. The caller may interact with the streams, inspect the status code,
    wait on command termination, etc.

    command: A list of strings representing the command and arguments.
    kwargs: A dictionary of parameters to be passed to subprocess.Popen().
            The parameters can be used to override stdin and stdout, for
            example.

    Returns: a Popen object.

    Note: method does not block."""

    logging.debug('running (non-blocking) \'%s\'.' % ' '.join(command))
    return self.GetCommandRunner().RunCommandPiped(command, **kwargs)

  def RunCommand(self, command, silent=False, timeout_secs=None):
    """Executes a remote command and waits for it to finish executing.

    Returns the exit code of the command."""

    logging.debug('running \'%s\'.' % ' '.join(command))
    return self.GetCommandRunner().RunCommand(command, silent,
                                              timeout_secs=timeout_secs)

  def EnsurePackageDataDirectoryExists(self, package_name):
    """Ensures that the specified package's isolated /data directory exists."""
    return self.RunCommand(
      ['mkdir','-p',_MapRemoteDataPathForPackage(package_name, 0)('/data')])

  def PutFile(self, source, dest, recursive=False, for_package=None):
    """Copies a file from the local filesystem to the target filesystem.

    source: The path of the file being copied.
    dest: The path on the remote filesystem which will be copied to.
    recursive: If true, performs a recursive copy.
    for_package: If specified, /data in the |dest| is mapped to the package's
                 isolated /data location.
    """

    assert type(source) is str
    self.PutFiles([source], dest, recursive, for_package)

  def PutFiles(self, sources, dest, recursive=False, for_package=None):
    """Copies files from the local filesystem to the target filesystem.

    sources: List of local file paths to copy from, or a single path.
    dest: The path on the remote filesystem which will be copied to.
    recursive: If true, performs a recursive copy.
    for_package: If specified, /data in the |dest| is mapped to the package's
                 isolated /data location.
    """

    assert type(sources) is tuple or type(sources) is list
    if for_package:
      self.EnsurePackageDataDirectoryExists(for_package)
      dest = _MapRemoteDataPathForPackage(for_package, 0)(dest)
    logging.debug('copy local:%s => remote:%s' % (sources, dest))
    self.GetCommandRunner().RunScp(sources, dest, remote_cmd.COPY_TO_TARGET,
                                   recursive)

  def GetFile(self, source, dest, for_package=None):
    """Copies a file from the target filesystem to the local filesystem.

    source: The path of the file being copied.
    dest: The path on the local filesystem which will be copied to.
    for_package: If specified, /data in paths in |sources| is mapped to the
                 package's isolated /data location.
    """
    assert type(source) is str
    self.GetFiles([source], dest, for_package)

  def GetFiles(self, sources, dest, for_package=None):
    """Copies files from the target filesystem to the local filesystem.

    sources: List of remote file paths to copy.
    dest: The path on the local filesystem which will be copied to.
    for_package: If specified, /data in paths in |sources| is mapped to the
                 package's isolated /data location.
    """
    assert type(sources) is tuple or type(sources) is list
    self._AssertIsStarted()
    if for_package:
      sources = map(_MapRemoteDataPathForPackage(for_package, 0), sources)
    logging.debug('copy remote:%s => local:%s' % (sources, dest))
    return self.GetCommandRunner().RunScp(sources, dest,
                                          remote_cmd.COPY_FROM_TARGET)

  def _GetEndpoint(self):
    """Returns a (host, port) tuple for the SSH connection to the target."""
    raise NotImplementedError

  def _GetTargetSdkArch(self):
    """Returns the Fuchsia SDK architecture name for the target CPU."""
    if self._target_cpu == 'arm64' or self._target_cpu == 'x64':
      return self._target_cpu
    raise FuchsiaTargetException('Unknown target_cpu:' + self._target_cpu)

  def _AssertIsStarted(self):
    assert self.IsStarted()

  def _WaitUntilReady(self, retries=_ATTACH_MAX_RETRIES):
    logging.info('Connecting to Fuchsia using SSH.')

    for retry in xrange(retries + 1):
      host, port = self._GetEndpoint()
      runner = remote_cmd.CommandRunner(self._GetSshConfigPath(), host, port)
      if runner.RunCommand(['true'], True) == 0:
        logging.info('Connected!')
        self._started = True
        return True
      time.sleep(_ATTACH_RETRY_INTERVAL)

    logging.error('Timeout limit reached.')

    raise FuchsiaTargetException('Couldn\'t connect using SSH.')

  def _GetSshConfigPath(self, path):
    raise NotImplementedError

  # TODO: remove this once all instances of architecture names have been
  # converted to the new naming pattern.
  def _GetTargetSdkLegacyArch(self):
    """Returns the Fuchsia SDK architecture name for the target CPU."""
    if self._target_cpu == 'arm64':
      return 'aarch64'
    elif self._target_cpu == 'x64':
      return 'x86_64'
    raise Exception('Unknown target_cpu %s:' % self._target_cpu)
