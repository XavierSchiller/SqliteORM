#include "xsqlite3.hpp"
#include "xsqlite3utils.hpp"
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

bool xsqlite::execute(std::string Query) {
  sqlite3_stmt *ppsmt;

  sqlite3_prepare_v2(this->db, Query.c_str(), static_cast<int>(Query.length()),
                     &ppsmt, nullptr);

  int step_track = sqlite3_step(ppsmt);
  while (step_track != SQLITE_DONE) {
    int cols = sqlite3_column_count(ppsmt);
    column datas;
    data d;
    for (int i = 0; i < cols; i++) {
      int type = sqlite3_column_type(ppsmt, i);
      switch (type) {
      case 1:
        d.type = 1;
        d.d = sqlite3_column_int(ppsmt, i);
        break;
      case 2:
        d.type = 2;
        d.d = sqlite3_column_double(ppsmt, i);
        break;
      case 3:
        d.type = 3;
        d.d = sqlite3_column_text(ppsmt, i);
        break;
      case 4:
        d.type = 4;
        d.d = sqlite3_column_text(ppsmt, i);
        break;
      }
      datas.element.push_back(d);
    } // inner for loop ends here.
    this->result.push_back(datas);
    step_track = sqlite3_step(ppsmt);
  } // while ends here.
}

xsqlite::xsqlite(xsqlite *x) {
  this->db = x->db;
  this->result = x->result;
  x->~xsqlite();
}
} // namespace xsqlite3
