#include "xsqlite3.hpp"
#include <algorithm>
#include <chrono>
#include <string>

std::string
random_string(size_t length)
{
  auto randchar = []() -> char {
    const char charset[] = "0123456789"
                           "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                           "abcdefghijklmnopqrstuvwxyz";
    const size_t max_index = (sizeof(charset) - 1);
    return charset[rand() % max_index];
  };
  std::string str(length, 0);
  std::generate_n(str.begin(), length, randchar);
  return str;
}
int
main()
{
  std::string queries[1000];
  for (int i = 0; i < 1000; i++) {
    queries[i] = "INSERT INTO t1 values(" + std::to_string(i) + "," +
                 std::to_string(rand()) + +",'" + random_string(30) + "');";
  }

  xsqlite3::xsqlite cl("rbs.db");

  std::chrono::steady_clock::time_point begin =
    std::chrono::steady_clock::now();

  cl.execute_update("create table t1(a INTEGER, b INTEGER, c VARCHAR(100));");

  for (int i = 0; i < 1000; i++) {
    cl.execute_update(queries[i]);
  }
  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

  
  std::cout << "Time difference = ";
  std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     begin)
                 .count();
  std::cout << "[µs]" << std::endl;
}