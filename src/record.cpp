#include "record.hpp"

namespace xsqlite3
{
int Record::num_col()
{
  return sqlite3_column_count(this->_ppsmt);
}
} // namespace xsqlite3