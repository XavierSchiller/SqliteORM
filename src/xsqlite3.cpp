#include "xsqlite3.hpp"
#include "xsqlite3utils.hpp"
#include <string>
namespace xsqlite3
{

// Constructor Segment ----------------------------------
xsqlite::xsqlite(std::string filename, sqliteopen flags)
{
  int status =
      sqlite3_open_v2(filename.c_str(), &db, flags, NULL); // Opening the file.
  if (status != SQLITE_OK)
  {
    throw sqlite3_error(this->db);
  }
  // File is opened successfully.
}

xsqlite::~xsqlite() { sqlite3_close(this->db); }

// General Segment ----------------------------------------
Record xsqlite::execute(std::string Query)
{
  sqlite3_stmt *ppsmt;

  int prep_track =
      sqlite3_prepare_v2(this->db, Query.c_str(),
                         static_cast<int>(Query.length()), &ppsmt, nullptr);

  // Find the Error if there.

  if (prep_track != SQLITE_OK)
    throw sqlite3_error(this->db);

  Record r(ppsmt);

  return r;
}

// Transaction Segment ------------------------------------
bool xsqlite::begin_transaction() { this->execute("BEGIN TRANSACTION"); }
bool xsqlite::begin_deferred_transaction()
{
  this->execute("BEGIN DEFERRED TRANSACTION");
}
bool xsqlite::begin_immediate_transaction()
{
  this->execute("BEGIN IMMEDIATE TRANSACTION");
}
bool xsqlite::begin_exclusive_transaction()
{
  this->execute("BEGIN EXCLUSIVE TRANSACTION");
}
bool xsqlite::commit_transaction() { this->execute("COMMIT TRANSACTION"); }
bool xsqlite::end_transaction() { this->execute("END TRANSACTION"); }
bool xsqlite::rollback() { this->execute("ROLLBACK"); }
bool xsqlite::rollback_transaction() { this->execute("ROLLBACK TRANSACTION"); }
bool xsqlite::rollback_transaction_to_savepoint(std::string savepoint)
{
  this->execute("ROLLBACK TRANSACTION TO SAVEPOINT" + savepoint);
}

} // namespace xsqlite3
