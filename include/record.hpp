#pragma once

#include <sqlite3.h>

namespace xsqlite3 {

// This class acts as a Record Varaible that gets a given record after a query.
class Record
{
private:
  sqlite3_stmt* _ppsmt;
  int step_track;
  // xyz
public:
  Record(sqlite3_stmt* ppsmt)
  {
    this->_ppsmt = ppsmt;
    this->step_track = sqlite3_step(this->_ppsmt);
  }
  ~Record() { sqlite3_finalize(_ppsmt); }
  bool has_next();
  bool next();
  template<typename T>
  T get(int index)
  {}

  int num_col();
};
} // namespace xsqlite3
