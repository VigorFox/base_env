// This is generated file. Do not modify directly.
// Path to the code generator: tools/generate_library_loader/generate_library_loader.py .

#ifndef LIBRARY_LOADER_LIBGIO_H
#define LIBRARY_LOADER_LIBGIO_H

#include <gio/gio.h>
#define LIBRARY_LOADER_LIBGIO_H_DLOPEN


#include <string>

class LibGioLoader {
 public:
  LibGioLoader();
  ~LibGioLoader();

  bool Load(const std::string& library_name)
      __attribute__((warn_unused_result));

  bool loaded() const { return loaded_; }

  decltype(&::glib_check_version) glib_check_version;
  decltype(&::g_type_init) g_type_init;
  decltype(&::g_settings_new) g_settings_new;
  decltype(&::g_settings_get_child) g_settings_get_child;
  decltype(&::g_settings_get_string) g_settings_get_string;
  decltype(&::g_settings_get_boolean) g_settings_get_boolean;
  decltype(&::g_settings_get_int) g_settings_get_int;
  decltype(&::g_settings_get_strv) g_settings_get_strv;
  decltype(&::g_settings_list_schemas) g_settings_list_schemas;


 private:
  void CleanUp(bool unload);

#if defined(LIBRARY_LOADER_LIBGIO_H_DLOPEN)
  void* library_;
#endif

  bool loaded_;

  // Disallow copy constructor and assignment operator.
  LibGioLoader(const LibGioLoader&);
  void operator=(const LibGioLoader&);
};

#endif  // LIBRARY_LOADER_LIBGIO_H
