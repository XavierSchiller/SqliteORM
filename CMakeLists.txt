cmake_minimum_required(VERSION 3.0.0)
project(SqliteORM VERSION 0.1.0)

add_subdirectory(tests)

set (CMAKE_CXX_STANDARD 11)

find_library(sql NAMES sqlite3)
if(${CMAKE_VERSION} VERSION_LESS 3.14)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else()
    cmake_policy(VERSION 3.14)
endif()

set(inclDir
    ./include/
)

set (SOURCE
    src/xsqlite3.cpp
    src/record.cpp
)

include_directories("./include")

add_library(SqliteORM ${SOURCE})
target_link_libraries(SqliteORM ${sql})
enable_testing()
add_test(NAME SampleTest COMMAND Test)