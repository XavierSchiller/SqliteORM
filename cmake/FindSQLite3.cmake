#FindSQLite.cmake 

#Finds if SQLite has been installed on the system.
find_package(PkgConfig)

find_path(SQLite3_INCLUDE_DIR
  NAMES sqlite3.h
)

find_library(SQLite3_LIBRARY
  NAMES sqlite3 
)

mark_as_advanced(SQLite3_FOUND SQLite3_INCLUDE_DIR SQLite3_VERSION SQLite3_LIBRARY)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SQLite3
  REQUIRED_VARS SQLite3_INCLUDE_DIR SQLite3_LIBRARY
  VERSION_VAR SQLite3_VERSION
)

if(SQLite3_FOUND)
  set(SQLite3_INCLUDE_DIRS ${SQLite3_INCLUDE_DIR})
  set(SQLite3_LIBRARIES ${SQLite3_LIBRARY})
endif()

if(SQLite3_FOUND AND NOT TARGET SQLite3::SQLite3)
  add_library(SQLite3::SQLite3 UNKNOWN IMPORTED)
  set_target_properties(SQLite3::SQLite3 PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${SQLite3_INCLUDE_DIR}"
    IMPORTED_LOCATION "${SQLite3_LIBRARY}"
  )
endif()
