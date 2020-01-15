#include "xsqlite3.hpp"
#include "xsqlite3utils.hpp"
#include <string>
namespace xsqlite3 {

void
Sqlite::open(std::string filename, SqliteOpen flags)
{
  int status =
    sqlite3_open_v2(filename.c_str(), &db, flags, NULL); // Opening the file.
  if (status != SQLITE_OK) {
    throw SqliteError(this->db);
  }
}

Sqlite::Sqlite(std::string filename, SqliteOpen flags)
{
  open(filename, flags);
}

Sqlite::Sqlite(std::string filename)
{
  open(filename, SqliteOpen::eReadWrite);
}

Sqlite::Sqlite(Sqlite& obj)
{
  this->db = obj.db;
}

Sqlite::~Sqlite()
{
  sqlite3_close(this->db);
}

sqlite3_stmt*
Sqlite::prepare(std::string Query)
{
  sqlite3_stmt* ppsmt;
  int prep_track = sqlite3_prepare_v2(
    this->db, Query.c_str(), static_cast<int>(Query.length()), &ppsmt, nullptr);

  if (prep_track != SQLITE_OK)
    throw SqliteError(this->db);

  return ppsmt;
}

Record
Sqlite::execute(std::string Query)
{
  sqlite3_stmt* ppsmt = this->prepare(Query);
  Record r(ppsmt);

  return r;
}

int
Sqlite::execute_update(std::string Query)
{
  sqlite3_stmt* ppsmt;

  int prep_track = sqlite3_prepare_v2(
    this->db, Query.c_str(), static_cast<int>(Query.length()), &ppsmt, nullptr);

  if (prep_track != SQLITE_OK)
    throw SqliteError(this->db);

  while (sqlite3_step(ppsmt) != SQLITE_DONE)
    ;

  return sqlite3_changes(this->db);
}

} // namespace xsqlite3
