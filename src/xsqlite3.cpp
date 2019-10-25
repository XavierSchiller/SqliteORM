#include "xsqlite3.hpp"
#include <string>
namespace xsqlite3 {

xsqlite::xsqlite(std::string filename, sqliteopen flags) {
  int status =
      sqlite3_open_v2(filename.c_str(), &db, flags, NULL); // Opening the file.
  if (status != SQLITE_OK) {
    std::string errmsg = sqlite3_errmsg(db);
    throw openerr(errmsg);
  }
  // File is opened successfully.
}

xsqlite::~xsqlite() { sqlite3_close(this->db); }
} // namespace xsqlite3