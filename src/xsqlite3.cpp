#include "xsqlite3.hpp"
#include "xsqlite3utils.hpp"
#include <string>
namespace xsqlite3 {

xsqlite::xsqlite(std::string filename, sqliteopen flags)
{
  int status =
    sqlite3_open_v2(filename.c_str(), &db, flags, NULL); // Opening the file.
  if (status != SQLITE_OK) {
    throw sqlite3_error(this->db);
  }
  // File is opened successfully.
}

xsqlite::~xsqlite()
{
  sqlite3_close(this->db);
}

Record
xsqlite::execute(std::string Query)
{
  sqlite3_stmt* ppsmt;

  int prep_track = sqlite3_prepare_v2(
    this->db, Query.c_str(), static_cast<int>(Query.length()), &ppsmt, nullptr);

  if (prep_track != SQLITE_OK)
    throw sqlite3_error(this->db);

  Record r(ppsmt);

  return r;
}

} // namespace xsqlite3
