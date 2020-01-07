#pragma once
#include "constants.hpp"
#include "sqlerror.hpp"
#include <iostream>
#include <sqlite3.h>
#include <string>
#include <tuple>
#include <vector>
#include <record.hpp>
namespace xsqlite3 {

class xsqlite {
private:
  sqlite3 *db;

public:
  // Constructors and Destructors.
  xsqlite(std::string filename, sqliteopen flags = sqliteopen::rw);
  ~xsqlite();

  // General Functions:
  Record execute(std::string Query);

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
  // Table Functions
  bool table_column_names(std::string table_name);

  // Stored Procedures.
  void add_stored_procedure();
  void execute_procedure();

  // Data Functions

  // Single Cell At a time

};

} // namespace xsqlite3