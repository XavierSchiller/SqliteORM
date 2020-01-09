#include "record.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <locale>

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

int
Record::col_type(int index)
{
  return sqlite3_column_type(this->_ppsmt, index);
}

int
Record::col_length(int index) // Figure out _bytes16() as well.
{
  return sqlite3_column_bytes(this->_ppsmt, index);
}

int
Record::get_int(int index)
{
  return sqlite3_column_int(this->_ppsmt, index);
}

int64_t
Record::get_int64(int index)
{
  return sqlite3_column_int64(this->_ppsmt, index);
}

double
Record::get_double(int index)
{
  return sqlite3_column_double(this->_ppsmt, index);
}

std::string
Record::get_text(int index)
{
  std::string res(
    reinterpret_cast<const char*>(sqlite3_column_text(this->_ppsmt, index)));
  return res;
}

std::u16string
Record::get_text16(int index)
{
  return std::u16string(reinterpret_cast<const char16_t*>(
    sqlite3_column_text16(this->_ppsmt, index)));
}

std::string
u16_to_ascii(std::u16string const& s)
{
  std::string out;
  std::transform(begin(s), end(s), back_inserter(out), [](char16_t c) {
    return c < 128 ? static_cast<char>(c) : '?';
  });
  return out;
}

} // namespace xsqlite3