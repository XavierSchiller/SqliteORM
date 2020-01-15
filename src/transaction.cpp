#include "transaction.hpp"
#include "record.hpp"
#include "sqlerror.hpp"
namespace xsqlite3 {

Transaction::Transaction(Sqlite obj)
  : Sqlite(obj)
{}

int
Transaction::Commit()
{
  int val =
    sqlite3_exec(this->db, "END TRANSACTION", nullptr, nullptr, nullptr);
}
}