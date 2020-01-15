#include "xsqlite3.hpp"
#include "xsqlite3utils.hpp"
#include <string>
namespace xsqlite3 {

void
xsqlite::open(std::string filename, SqliteOpen flags)
{
  int status =
    sqlite3_open_v2(filename.c_str(), &db, flags, NULL); // Opening the file.
  if (status != SQLITE_OK) {
    throw sqlite3_error(this->db);
  }
}

xsqlite::xsqlite(std::string filename, SqliteOpen flags)
{
  open(filename, flags);
}

xsqlite::xsqlite(std::string filename)
{
  open(filename, SqliteOpen::eReadWrite);
}

xsqlite::xsqlite(xsqlite& obj)
{
  this->db = obj.db;
}

xsqlite::~xsqlite()
{
  sqlite3_close(this->db);
}

sqlite3_stmt*
xsqlite::prepare(std::string Query)
{
  sqlite3_stmt* ppsmt;
  int prep_track = sqlite3_prepare_v2(
    this->db, Query.c_str(), static_cast<int>(Query.length()), &ppsmt, nullptr);

  if (prep_track != SQLITE_OK)
    throw sqlite3_error(this->db);

  return ppsmt;
}

Record
xsqlite::execute(std::string Query)
{
  sqlite3_stmt* ppsmt = this->prepare(Query);
  Record r(ppsmt);

  return r;
}

int
xsqlite::execute_update(std::string Query)
{
  sqlite3_stmt* ppsmt;

  int prep_track = sqlite3_prepare_v2(
    this->db, Query.c_str(), static_cast<int>(Query.length()), &ppsmt, nullptr);

  if (prep_track != SQLITE_OK)
    throw sqlite3_error(this->db);

  while (sqlite3_step(ppsmt) != SQLITE_DONE)
    ;

  return sqlite3_changes(this->db);
}

} // namespace xsqlite3
