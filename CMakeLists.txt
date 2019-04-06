cmake_minimum_required(VERSION 3.0.0)
project(SqliteORM VERSION 0.1.0)

find_library(sql NAMES sqlite3)

if(${CMAKE_VERSION} VERSION_LESS 3.14)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else()
    cmake_policy(VERSION 3.14)
endif()

add_executable(SqliteORM src/simple.cpp)
target_link_libraries(SqliteORM ${sql})