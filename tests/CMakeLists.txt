add_executable(Test
    Sample.cpp
)

add_executable(TTest
    TableTest.cpp
)

include_directories(
    ../include/
)

target_link_libraries(
    Test
    SqliteORM
)

target_link_libraries(
    TTest
    SqliteORM
)