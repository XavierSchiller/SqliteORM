#pragma once
#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <vector>
namespace xsqlite3 {

class any {
private:
  void *_data;
  const std::type_info &otype;
  bool cnst;

public:
  template <typename T>
  any(T data) : _data(), otype(typeid(T)), cnst(std::is_const<T>::value) {
    T *val = new T;
    *val = data;
    this->_data = val;
  }

  void dest() {
    if (typeid(int) == this->otype) {
      delete static_cast<int *>(this->_data);
    } else if (typeid(double) == this->otype) {
      delete static_cast<double *>(this->_data);
    } else {
      delete static_cast<const char *>(this->_data);
    }
  }

  template <typename T> T get() {
    if (typeid(T) != this->otype || this->cnst && !std::is_const<T>::value) {
      throw std::bad_cast{};
    } else {
      return *static_cast<T *>(const_cast<void *>(_data));
    }
  }
};
} // namespace xsqlite3