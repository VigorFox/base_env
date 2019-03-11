# Copyright 2018 The Chromium Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

import os
import re


_CMDLINE_NAME_SEGMENT_RE = re.compile(
    r' with(?:out)? \{[^\}]*\}')

class ConflictingPositiveFiltersException(Exception):
  """Raised when both filter file and filter argument have positive filters."""


def ParseFilterFile(input_lines):
  """Converts test filter file contents to positive and negative pattern lists.

  See //testing/buildbot/filters/README.md for description of the
  syntax that |input_lines| are expected to follow.

  See
  https://github.com/google/googletest/blob/master/googletest/docs/AdvancedGuide.md#running-a-subset-of-the-tests
  for description of the syntax that --gtest_filter argument should follow.

  Args:
    input_lines: An iterable (e.g. a list or a file) containing input lines.
  Returns:
    tuple containing the lists of positive patterns and negative patterns
  """
  # Strip comments and whitespace from each line and filter non-empty lines.
  stripped_lines = (l.split('#', 1)[0].strip() for l in input_lines)
  filter_lines = [l for l in stripped_lines if l]

  # Split the tests into positive and negative patterns (gtest treats
  # every pattern after the first '-' sign as an exclusion).
  positive_patterns = [l for l in filter_lines if l[0] != '-']
  negative_patterns = [l[1:] for l in filter_lines if l[0] == '-']
  return positive_patterns, negative_patterns


def AddFilterOptions(parser):
  """Adds filter command-line options to the provided parser.

  Args:
    parser: an argparse.ArgumentParser instance.
  """
  parser.add_argument(
      # Deprecated argument.
      '--gtest-filter-file',
      # New argument.
      '--test-launcher-filter-file',
      dest='test_filter_file', type=os.path.realpath,
      help='Path to file that contains googletest-style filter strings. '
           'See also //testing/buildbot/filters/README.md.')

  filter_group = parser.add_mutually_exclusive_group()
  filter_group.add_argument(
      '-f', '--test-filter', '--gtest_filter', '--gtest-filter',
      dest='test_filter',
      help='googletest-style filter string.',
      default=os.environ.get('GTEST_FILTER'))
  filter_group.add_argument(
      '--isolated-script-test-filter',
      help='isolated script filter string. '
           'Like gtest filter strings, but with :: separators instead of :')

def InitializeFilterFromArgs(args):
  """Returns a filter string from the command-line option values.

  Args:
    args: an argparse.Namespace instance resulting from a using parser
      to which the filter options above were added.

  Raises:
    ConflictingPositiveFiltersException if both filter file and command line
    specify positive filters.
  """
  positive_patterns = []
  negative_patterns = []
  if args.isolated_script_test_filter:
    args.test_filter = args.isolated_script_test_filter.replace('::', ':')
  if args.test_filter:
    parsed_filter = _CMDLINE_NAME_SEGMENT_RE.sub(
        '', args.test_filter.replace('#', '.'))
    split_filter = parsed_filter.split('-', 1)
    positive = ''
    negative = ''
    if len(split_filter) == 1:
      positive = split_filter[0]
    else:
      positive, negative = split_filter
    positive_patterns = [f for f in positive.split(':') if f]
    negative_patterns = [f for f in negative.split(':') if f]


  if args.test_filter_file:
    with open(args.test_filter_file, 'r') as f:
      positive_file_patterns, negative_file_patterns = ParseFilterFile(f)
      if positive_file_patterns:
        if positive_patterns:
          raise ConflictingPositiveFiltersException(
              'Cannot specify positive pattern in both filter file and ' +
              'filter command line argument')
        positive_patterns = positive_file_patterns
      negative_patterns.extend(negative_file_patterns)

  final_filter = ':'.join(positive_patterns)
  if negative_patterns:
    final_filter += '-' + ':'.join(negative_patterns)
  return final_filter