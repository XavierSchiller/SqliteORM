#include "xsqlite3.hpp"
#include "xsqlite3utils.hpp"
#include <string>

namespace xsqlite3 {

// Constructor Segment ----------------------------------
xsqlite::xsqlite(std::string filename, sqliteopen flags) {
  int status =
      sqlite3_open_v2(filename.c_str(), &db, flags, NULL); // Opening the file.
  if (status != SQLITE_OK) {
    throw sqlite3_error(this->db);
  }
  // File is opened successfully.
}

xsqlite::xsqlite(xsqlite *x) {
  this->db = x->db;
  this->result = x->result;
  x->~xsqlite();
}

xsqlite::~xsqlite() { sqlite3_close(this->db); }

// General Segment ----------------------------------------
bool xsqlite::execute(std::string Query) {
  sqlite3_stmt *ppsmt;

  int prep_track =
      sqlite3_prepare_v2(this->db, Query.c_str(),
                         static_cast<int>(Query.length()), &ppsmt, nullptr);

  // Find the Error if there.

  if (prep_track != SQLITE_OK)
    throw sqlite3_error(this->db);

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
        d.d = reinterpret_cast<const char *>(sqlite3_column_text(ppsmt, i));
        break;
      case 4:
        d.type = 4;
        d.d = reinterpret_cast<const char *>(sqlite3_column_text(ppsmt, i));
        break;
      }
      datas.element.push_back(d);
    } // inner for loop ends here.
    this->result.push_back(datas);
    step_track = sqlite3_step(ppsmt);
  } // while ends here.

  sqlite3_finalize(ppsmt);

  return true;
}

bool xsqlite::execute(std::initializer_list<std::string> Queries) {
  for (std::string x : Queries) {
    this->execute(x);
  }
}

// Transaction Segment ------------------------------------
bool xsqlite::begin_transaction() { this->execute("BEGIN TRANSACTION"); }
bool xsqlite::begin_deferred_transaction() {
  this->execute("BEGIN DEFERRED TRANSACTION");
}
bool xsqlite::begin_immediate_transaction() {
  this->execute("BEGIN IMMEDIATE TRANSACTION");
}
bool xsqlite::begin_exclusive_transaction() {
  this->execute("BEGIN EXCLUSIVE TRANSACTION");
}
bool xsqlite::commit_transaction() { this->execute("COMMIT TRANSACTION"); }
bool xsqlite::end_transaction() { this->execute("END TRANSACTION"); }
bool xsqlite::rollback() { this->execute("ROLLBACK"); }
bool xsqlite::rollback_transaction() { this->execute("ROLLBACK TRANSACTION"); }
bool xsqlite::rollback_transaction_to_savepoint(std::string savepoint) {
  this->execute("ROLLBACK TRANSACTION TO SAVEPOINT" + savepoint);
}

} // namespace xsqlite3
