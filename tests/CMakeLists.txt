add_executable(Test
    Sample.cpp
)

include_directories(
    ../include/
)

target_link_libraries(
    Test
    SqliteORM
)
