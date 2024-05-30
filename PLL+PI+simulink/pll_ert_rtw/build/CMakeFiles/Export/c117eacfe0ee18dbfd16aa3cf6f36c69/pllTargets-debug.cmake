#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "pll::pll_objects" for configuration "Debug"
set_property(TARGET pll::pll_objects APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(pll::pll_objects PROPERTIES
  IMPORTED_COMMON_LANGUAGE_RUNTIME_DEBUG ""
  IMPORTED_OBJECTS_DEBUG "${_IMPORT_PREFIX}/pll_ert_rtw/objects-Debug/pll_objects/pll.c.obj;${_IMPORT_PREFIX}/pll_ert_rtw/objects-Debug/pll_objects/pll_capi.c.obj"
  )

list(APPEND _cmake_import_check_targets pll::pll_objects )
list(APPEND _cmake_import_check_files_for_pll::pll_objects "${_IMPORT_PREFIX}/pll_ert_rtw/objects-Debug/pll_objects/pll.c.obj;${_IMPORT_PREFIX}/pll_ert_rtw/objects-Debug/pll_objects/pll_capi.c.obj" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
