#include "transaction.hpp"
#include "record.hpp"
#include "sqlerror.hpp"
namespace xsqlite3 {

Transaction::Transaction(Sqlite obj)
  : Sqlite(obj)
{
  int val =
    sqlite3_exec(this->db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);

  if (val != SQLITE_DONE)
    throw SqliteError(this->db);
}

int
Transaction::Commit()
{
  int val =
    sqlite3_exec(this->db, "END TRANSACTION", nullptr, nullptr, nullptr);

  if (val != SQLITE_DONE)
    throw SqliteError(this->db);
}
}