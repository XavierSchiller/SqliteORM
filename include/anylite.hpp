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
  any(T *data) : _data(data), otype(typeid(T)), cnst(std::is_const<T>::value) {}

  template <typename T> T get() {
    if (typeid(T) != this->otype || this->cnst && !std::is_const<T>::value) {
      throw std::bad_cast{};
    } else {
      return *static_cast<T *>(const_cast<void *>(_data));
    }
  }
};

} // namespace xsqlite3