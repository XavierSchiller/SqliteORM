#pragma once
#include "record.hpp"
#include "sqlite3.h"
#include "xsqlite3.hpp"
#include <string>
namespace xsqlite3 {

class Transaction : public xsqlite
{
public:
  Transaction(xsqlite obj);
  int commit(); // Needs to return status codes.
};
}