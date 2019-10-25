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
  any d;
};

struct column {
  std::vector<data> element;
};

class xsqlite {
private:
public:
  sqlite3 *db;
  std::vector<column> result;

  xsqlite(std::string filename, sqliteopen flags = sqliteopen::rw);
  ~xsqlite();
  bool execute(std::string Query);
};

inline sqliteopen operator|(sqliteopen dest, sqliteopen src) {
  return static_cast<sqliteopen>(static_cast<int>(dest) |
                                 static_cast<int>(src));
}


} // namespace xsqlite3