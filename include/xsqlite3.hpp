#pragma once
#include "sqlerror.hpp"
#include <iostream>
#include <sqlite3.h>
#include <string>
#include <vector>

#include "any.hpp"
namespace xsqlite3 {

enum sqliteopen {
  read = SQLITE_OPEN_READONLY,
  write = SQLITE_OPEN_READWRITE,
  rw = SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE,
  create = SQLITE_OPEN_CREATE,
  nom = SQLITE_OPEN_NOMUTEX,
  fullm = SQLITE_OPEN_FULLMUTEX,
  ouri = SQLITE_OPEN_URI,
  mem = SQLITE_OPEN_MEMORY,
  scache = SQLITE_OPEN_SHAREDCACHE,
  pcache = SQLITE_OPEN_PRIVATECACHE
};

inline sqliteopen operator|(sqliteopen dest, sqliteopen src) {
  return static_cast<sqliteopen>(static_cast<int>(dest) |
                                 static_cast<int>(src));
}

enum sqlite_column_types {
  integer,
  longinteger,
  floating,
  doublep,
  blob,
  null,
  text
};

struct data {
  int type;
  nonstd::any d;
};

struct column {
  std::vector<data> element;
};

class xsqlite {
private:
  sqlite3 *db;
  std::vector<column> result;

public:
  xsqlite(std::string filename, sqliteopen flags = sqliteopen::rw);
  xsqlite(xsqlite *x) {
    this->db = x->db;
    this->result = x->result;
    x->~xsqlite();
  }
  ~xsqlite();
  bool execute(std::string Query);

  template <typename T> T get_data(int row, int col) {
    return nonstd::any_cast<T>(this->result.at(row).element.at(col).d);
  }
};

// Class to take care of binding functions.
class Query {
private:
  std::string q;
  template <typename T> std::string toString(const T &t) {
    return std::to_string(t);
  }

  std::string toString(const char *t) { return t; }

  std::string toString(const std::string &t) { return t; }

public:
  Query(std::string ip) { this->q = ip; }
  template <typename T, typename... Types> void bind(T a, Types... b) {
    bind(a);
    bind(b...);
  };

  template <typename T> void bind(T a) {
    try {
      q.replace(q.find("$$"), 2, this->toString(a).c_str());
    } catch (std::out_of_range e) {
      throw std::invalid_argument("Too many arguments.");
    }
  }

  std::string to_string() { return q.c_str(); }
};

} // namespace xsqlite3