#include "transaction.hpp"
#include "sqlerror.hpp"
namespace xsqlite3 {

Transaction::Transaction(sqlite3* db)
{
  this->db = db;
  int val =
    sqlite3_exec(this->db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);
  if (val != SQLITE_DONE)
    throw sqlite3_error(db);
}


void
Transaction::commit()
{
  int val =
    sqlite3_exec(this->db, "END TRANSACTION", nullptr, nullptr, nullptr);
}

int Transaction::executeUpdate(std::string query){}
Record Transaction::executeSelect(std::string query){}
}