#pragma once
#include "record.hpp"
#include "sqlite3.h"
#include "xsqlite3.hpp"
#include <string>
namespace xsqlite3 {

class Transaction : public Sqlite
{
public:
  Transaction(Sqlite obj);
  int commit(); // Needs to return status codes.
};
}