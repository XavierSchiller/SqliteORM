#pragma once
#include <stdexcept>
#include <string>
namespace xsqlite3 {
class Query
{
private:
  std::string q;
  template<typename T>
  std::string toString(const T& t)
  {
    return std::to_string(t);
  }

  std::string toString(const char* t) { return t; }

  std::string toString(const std::string& t) { return t; }

public:
  Query(std::string ip) { this->q = ip; }
  template<typename T, typename... Types>
  void bind(T a, Types... b)
  {
    bind(a);
    bind(b...);
  };

  template<typename T>
  void bind(T a)
  {
    try {
      q.replace(q.find("$$"), 2, this->toString(a).c_str());
    } catch (std::out_of_range e) {
      throw std::invalid_argument("Too many arguments.");
    }
  }

  std::string to_string() { return q.c_str(); }
};
} // namespace xsqlite3