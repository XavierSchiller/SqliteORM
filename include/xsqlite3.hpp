#pragma once
#include "any.hpp"
#include "constants.hpp"
#include "sqlerror.hpp"


#include <iostream>
#include <sqlite3.h>
#include <string>
#include <vector>
namespace xsqlite3 {

struct data {
  int type;
  nonstd::any d;
};

struct column {
  std::vector<data> element;
};

class xsqlite {
private:
  sqlite3 *db;
  std::vector<column> result;

public:
  xsqlite(std::string filename, sqliteopen flags = sqliteopen::rw);
  xsqlite(xsqlite *x);
  ~xsqlite();
  bool execute(std::string Query);

  template <typename T> T get_data(int row, int col) {
    return nonstd::any_cast<T>(this->result.at(row).element.at(col).d);
  }
};

// Class to take care of binding functions.

} // namespace xsqlite3