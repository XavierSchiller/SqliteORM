include_directories(
    ../include/
)

add_executable(Test
    Sample.cpp
)

add_executable(TTest
    TimeTest.cpp
)

target_link_libraries(
    Test
    SqliteORM
)

target_link_libraries(
    TTest
    SqliteORM
)
