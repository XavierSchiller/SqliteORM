#pragma once
#include <sqlite3.h>
#include <string>

namespace xsqlite3 {

class Transaction
{
private:
  sqlite3* db; // Sort of looks dangerous.

public:
  Transaction(sqlite3* db);
  int executeUpdate(std::string query);
  int executeSelect(std::string query); // Becasuse of Select
};
}