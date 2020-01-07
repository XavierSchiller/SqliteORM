#pragma once
#include "constants.hpp"
#include "sqlerror.hpp"
#include "record.hpp"
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <sqlite3.h>
namespace xsqlite3
{

class xsqlite
{
private:
  sqlite3 *db;

public:
  // Constructors and Destructors.
  xsqlite(std::string filename, sqliteopen flags = sqliteopen::rw);
  ~xsqlite();

  // General Functions:
  Record execute(std::string Query);
  int execute_update(std::string Query);

  // Special Functions (Pragma etc)
  std::vector<std::string> table_info(std::string tablename);

  // Table Functions
  bool table_column_names(std::string table_name);

};

} // namespace xsqlite3