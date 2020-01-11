cmake_minimum_required(VERSION 3.1...3.15) #Minimum version for Ubuntu 18.04

#Cmake Policy -- https://cliutils.gitlab.io/modern-cmake/chapters/basics.html


if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else()
    cmake_policy(VERSION 3.12)
    endif()
    
#Project Details:

project(SqliteORM 
VERSION 1.0.0
DESCRIPTION "A small Wrapper for Sqlite"
LANGUAGES CXX
)


#Set CXX Flags:
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -O6 -DNDEBUG=1")
find_package(Sqlite3 REQUIRED)
if(UNIX)
    find_package(Threads)
endif()
#Set Library Files:
set (SOURCE
src/xsqlite3.cpp
src/record.cpp
src/transaction.cpp
)

add_library(SqliteORM STATIC ${SOURCE})
target_link_libraries(SqliteORM sqlite3::sqlite3)
target_include_directories(SqliteORM
    PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

#Testing: -- Uses GoogleTest

option(PACKAGE_TESTS "Build the tests" ON)
if(PACKAGE_TESTS)
    enable_testing()
    include(GoogleTest)
    add_subdirectory(tests)
endif()