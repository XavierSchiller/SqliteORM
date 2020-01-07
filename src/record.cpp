#include "record.hpp"

namespace xsqlite3 {
int
Record::num_col()
{
  return sqlite3_column_count(this->_ppsmt);
}

bool
Record::has_next()
{
  return (this->step_track != SQLITE_DONE);
}

bool
Record::next()
{
  sqlite3_step(this->_ppsmt);
  return (this->step_track != SQLITE_DONE);
}
} // namespace xsqlite3