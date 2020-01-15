#pragma once
#include "constants.hpp"
#include "record.hpp"
#include "sqlerror.hpp"
#include "sqlite3.h"
#include <string>
namespace xsqlite3 {

class Sqlite
{
protected:
  sqlite3* db;
  void Open(std::string filename, SqliteOpen flags);
  sqlite3_stmt* Prepare(std::string Query);

public:
  // Constructors and Destructors.
  Sqlite(std::string filename, SqliteOpen flags);
  Sqlite(std::string filename);
  Sqlite(Sqlite &obj);
  ~Sqlite();

  // General Functions:
  Record Execute(std::string Query);
  int ExecuteUpdate(std::string Query);
};

} // namespace xsqlite3