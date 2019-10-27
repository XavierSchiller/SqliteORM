#pragma once
#include "any.hpp"
#include "constants.hpp"
#include "sqlerror.hpp"
#include <iostream>
#include <sqlite3.h>
#include <string>
#include <tuple>
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
  // Constructors and Destructors.
  xsqlite(std::string filename, sqliteopen flags = sqliteopen::rw);
  xsqlite(xsqlite *x);
  ~xsqlite();

  // General Functions:
  bool execute(std::string Query);
  bool execute(std::initializer_list<std::string> Queries);

  // Special Functions (Pragma etc)
  std::vector<std::string> table_info(std::string tablename);

  // Transactions Functions.
  bool begin_transaction();
  bool begin_deferred_transaction();
  bool begin_immediate_transaction();
  bool begin_exclusive_transaction();
  bool commit_transaction();
  bool end_transaction();
  bool rollback();
  bool rollback_transaction();
  bool rollback_transaction_to_savepoint(std::string savepoint);

  // Convineince functions
  bool delete_table();
  bool delete_row_from_table_where();

  // Stored Procedures.
  void add_stored_procedure();
  void execute_procedure();

  // Data Functions
  template <typename T> T get_data(int row, int col) {
    return nonstd::any_cast<T>(this->result.at(row).element.at(col).d);
  }

};

} // namespace xsqlite3