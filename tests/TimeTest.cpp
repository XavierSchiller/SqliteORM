#include "xsqlite3.hpp"
#include <algorithm>
#include <chrono>
#include <string.h>
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
main_wrapper_test()
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
    std::cout << "Executing:" << i << std::endl;
  }
  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

  std::cout << "Time difference = ";
  std::cout
    << std::chrono::duration_cast<std::chrono::seconds>(end - begin).count();
  std::cout << "[µs]" << std::endl;
}

inline void
sqlite3_exec_b(sqlite3* db, const char* q, int len)
{
  sqlite3_stmt* ppsmt;

  int prep_track = sqlite3_prepare_v2(db, q, len, &ppsmt, nullptr);

  if (prep_track != SQLITE_OK)
    exit(0);
  while (sqlite3_step(ppsmt) != SQLITE_DONE)
    ;
}

int
main_non_wrapper_test()
{
  const char* is = "create table t1(a INTEGER, b INTEGER, c VARCHAR(100));";
  int islen = strlen(is);
  std::string qs[1000];
  for (int i = 0; i < 1000; i++) {
    qs[i] = "INSERT INTO t1 values(" + std::to_string(i) + "," +
            std::to_string(rand()) + +",'" + random_string(30) + "');";
  }

  const char* filename = "rb.db";
  sqlite3* db;
  int status = sqlite3_open_v2(filename,
                               &db,
                               SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE,
                               NULL); // Opening the file.

  std::chrono::steady_clock::time_point begin =
    std::chrono::steady_clock::now();

  sqlite3_exec_b(db, is, islen);

  for (int i = 0; i < 1000; i++) {
    sqlite3_exec_b(db, qs[i].c_str(), qs[i].length());
    std::cout << "Executing:" << i << std::endl;
  }
  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

  std::cout << "Time difference = ";
  std::cout
    << std::chrono::duration_cast<std::chrono::seconds>(end - begin).count();
  std::cout << "[µs]" << std::endl;
}

int
main()
{
  main_non_wrapper_test();
}