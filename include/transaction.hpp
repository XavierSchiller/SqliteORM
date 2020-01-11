#pragma once
#include "sqlite3/sqlite3.h"
#include <string>
#include "record.hpp"
namespace xsqlite3 {

class Transaction
{
private:
  sqlite3* db;
public:
  Transaction(sqlite3* db);
  int executeUpdate(std::string query);
  Record executeSelect(std::string query); // Becasuse of Select
  void commit();
};
}