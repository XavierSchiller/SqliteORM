#pragma once

#include <sqlite3.h>

namespace xsqlite3
{

//This class acts as a Record Varaible that gets a given record after a query.
class Record
{
private:
  sqlite3_stmt *_ppsmt;
  //xyz
public:
  Record(sqlite3_stmt *ppsmt)
  {
    this->_ppsmt = ppsmt;
  }
  bool has_next();
  bool next();
  template <typename T>
  T get()
  {
    //Do Get the value.
  }

  int col_num()
  {
    return sqlite3_column_count(this->_ppsmt);
  }
};
} // namespace xsqlite3

/*
  int step_track = sqlite3_step(ppsmt);
  while (step_track != SQLITE_DONE)
  {
    int cols = sqlite3_column_count(ppsmt);
    column datas;
    for (int i = 0; i < cols; i++)
    {
      int type = sqlite3_column_type(ppsmt, i);
      switch (type)
      {
      case 1:
        datas.element.push_back(sqlite3_column_int(ppsmt, i));
        break;
      case 2:
        datas.element.push_back(sqlite3_column_double(ppsmt, i));
        break;
      case 3:
      case 4:
        datas.element.push_back(reinterpret_cast<const char *>(sqlite3_column_text(ppsmt, i)));
        break;
      }
    } // inner for loop ends here.
    this->result.push_back(datas);
    step_track = sqlite3_step(ppsmt);
  } // while ends here.

  sqlite3_finalize(ppsmt);
*/

/*
  template <typename T> T get_data(int row, int col) {
    return nonstd::any_cast<T>(this->result.at(row).element.at(col));
  }

  // Entire Record in one tuple.
  template <class A, class B, class... T>
  std::tuple<A, B, T...> get_data_record(int row) {
    int cols = 0;
    std::tuple<A, B, T...> record = {get_data<A>(row, cols++),
                                     get_data<B>(row, cols++),
                                     get_data<T>(row, cols++)...};
    return record;
  }

  template <class A> std::tuple<A> get_data_record(int row) {
    std::tuple<A> record = {get_data<A>(row, 0)};
    return record;
  }
*/