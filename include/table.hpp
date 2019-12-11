#pragma once
#include "anylite.hpp"
#include <iostream>
#include <vector>
namespace xsqlite3 {

class record {
private:
  std::vector<any> _record;

public:
  // Inputting Records
  template <typename T> void input_data(T data) {
    this->_record.push_back(data);
  }

  // Retrive The records
  template <typename T> T get_data(int col) {
    return this->_record.at(col).get<T>();
  }

  // Entire Record in one tuple.
  template <class A, class B, class... T>
  std::tuple<A, B, T...> get_data_record() {
    int cols = 0;
    std::tuple<A, B, T...> record = {get_data<A>(cols++), get_data<B>(cols++),
                                     get_data<T>(cols++)...};
    return record;
  }

  template <class A> std::tuple<A> get_data_record() {
    std::tuple<A> record = {get_data<A>(0)};
    return record;
  }

  void clear() {
    for (auto x : this->_record) {
      x.dest();
    }
  }
};

class table {
private:
  std::vector<record *> _table;

public:
  inline record *get_record_at(int index) { return this->_table.at(index); }

  inline void input_record(record *r) { this->_table.push_back(r); }

  void clear_records() {
    for (auto x : _table) {
      x->clear();
    }
  }
};
} // namespace xsqlite3