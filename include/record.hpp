#pragma once

#include <sqlite3.h>
#include <string>

namespace xsqlite3 {

// This class acts as a Record Varaible that gets a given record after a query.
class Record
{
private:
  sqlite3_stmt* _ppsmt;
  int step_track;

  // get_X functions
  int get_int(int index);
  int64_t get_int64(int index);
  double get_double(int index);
  void* get_blob(int index);
  std::string get_text(int index);
  std::u16string get_text16(int index);

public:
  // Constructors
  Record(sqlite3_stmt* ppsmt)
  {
    this->_ppsmt = ppsmt;
    this->step_track = sqlite3_step(this->_ppsmt);
  }
  ~Record() { sqlite3_finalize(_ppsmt); }

  // Reporting functions.
  bool has_next();
  bool next();

  // utility functions.
  int num_col();
  int col_length(int index);
  int col_type(int index);

  template<typename T>
  T get(int index){};
};

//-------------------Template Specializations

template<>
inline int // inline is necessary for the function to work.
Record::get<int>(int index)
{
  return this->get_int(index);
}

template<>
inline double // inline is necessary for the function to work.
Record::get<double>(int index)
{
  return this->get_double(index);
}

template<>
inline std::string // inline is necessary for the function to work.
Record::get<std::string>(int index)
{
  return this->get_text(index);
}

template<>
inline std::u16string // inline is necessary for the function to work.
Record::get<std::u16string>(int index)
{
  return this->get_text16(index);
}

template<>
inline int64_t // inline is necessary for the function to work.
Record::get<int64_t>(int index)
{
  return this->get_int64(index);
}

template<>
inline void* // inline is necessary for the function to work.
Record::get<void*>(int index)
{
  return this->get_blob(index);
}

//--------------------Other Functions
std::string
u16_to_ascii(std::u16string const& s);
} // namespace xsqlite3
