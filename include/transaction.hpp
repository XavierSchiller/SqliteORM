#pragma once
#include "record.hpp"
#include "sqlite3.h"
#include "xsqlite3.hpp"
#include <string>
namespace xsqlite3 {

class Transaction : public xsqlite
{
private:
  sqlite3* db;

public:
  Transaction(sqlite3* db);
  int commit(); // Needs to return status codes.
};
}