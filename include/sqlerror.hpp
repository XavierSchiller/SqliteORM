#pragma once
#include "sqlite3.h"
#include <stdexcept>
namespace xsqlite3 {
class SqliteError : public std::exception
{
  std::string errmsg;

public:
  SqliteError(sqlite3* db) { this->errmsg = sqlite3_errmsg(db); }
  const char* what() const noexcept override { return errmsg.c_str(); }
};

} // namespace xsqlite3