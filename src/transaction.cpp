#include "transaction.hpp"
#include "record.hpp"
#include "sqlerror.hpp"
namespace xsqlite3 {

Transaction::Transaction(xsqlite obj)
  : xsqlite(obj)
{}

int
Transaction::commit()
{
  int val =
    sqlite3_exec(this->db, "END TRANSACTION", nullptr, nullptr, nullptr);
}
}