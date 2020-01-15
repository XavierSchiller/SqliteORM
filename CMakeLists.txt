#Cmake Policy -- https://cliutils.gitlab.io/modern-cmake/chapters/basics.html
#Refer to: https://cmake.org/cmake/help/v3.10/manual/cmake-buildsystem.7.html


# Set the Minimum version of CMake: https://cmake.org/cmake/help/v3.10/command/cmake_minimum_required.html
# Setting FATAL_ERROR: Not wanting to deal with version 3.10.2 or lower
# 3.10.2 was released on October 12 2017.
cmake_minimum_required(VERSION 3.10.2 FATAL_ERROR)

# Currently Leaving out policy because of backwards compatibility of CMake.
# See: https://cmake.org/cmake/help/v3.10/command/cmake_policy.html


option(PACKAGE_TESTS "Build the tests" ON)

# -------------------------------------------------------------------------------
# Project Details:
project(SqliteORM 
    VERSION 1.0.0
    DESCRIPTION "A small Wrapper for Sqlite"
    LANGUAGES CXX
)


# ----------------------------------------------------------------------------------

# Ensuring that SQLite3 Packages are found via FindSQLite3.cmake

# Appends the Path of FindSQLite3.cmake into the search path of CMAKE_MODULES.
# Always use PROJECT_SOURCE_DIR to refer to the directory of the most recent project() call.
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")


# Finds SQLite3 and imports it via Module Mode.
# See: https://cmake.org/cmake/help/v3.10/command/find_package.html
# SQLite3 is absolutely Required, hence the required.
find_package(SQLite3 REQUIRED)


# ----------------------------------------------------------------------------------



#Set the source files that the library will be built on
set (SOURCE
    ${PROJECT_SOURCE_DIR}/src/xsqlite3.cpp
    ${PROJECT_SOURCE_DIR}/src/record.cpp
    ${PROJECT_SOURCE_DIR}/src/transaction.cpp
)


#Define a target SqliteORM that is the target with all our files. 
add_library(SqliteORM STATIC ${SOURCE})

# Set the target properties.
# See: https://cmake.org/cmake/help/v3.10/manual/cmake-properties.7.html#target-properties
# See: https://cmake.org/cmake/help/v3.10/command/set_target_properties.html
set_target_properties(SqliteORM
    PROPERTIES 
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED ON
)



target_include_directories(SqliteORM
    PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
target_link_libraries(SqliteORM SQLite3::SQLite3)

#Testing: -- Uses GoogleTest

if(PACKAGE_TESTS)
    enable_testing()
    include(GoogleTest)
    add_subdirectory(tests)
endif()