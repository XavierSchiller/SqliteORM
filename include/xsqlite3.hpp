#pragma once
#include "constants.hpp"
#include "record.hpp"
#include "sqlerror.hpp"
#include "sqlite3.h"
#include <string>
namespace xsqlite3 {

class xsqlite
{
private:
  sqlite3* db;
  void open(std::string filename, sqliteopen flags);
  sqlite3_stmt* prepare(std::string Query);
public:
  // Constructors and Destructors.
  xsqlite(std::string filename, sqliteopen flags);
  xsqlite(std::string filename);
  ~xsqlite();

  // General Functions:
  Record execute(std::string Query);
  int execute_update(std::string Query);

};

} // namespace xsqlite3