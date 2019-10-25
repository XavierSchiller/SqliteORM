#pragma once
#include "sqlerror.hpp"
#include <iostream>
#include <sqlite3.h>
#include <string>
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

union Data {
  const char *cdata;
  int idata;
  long int ldata;
  float fdata;
  double ddata;
  const void *b;
};

class xsqlite {
private:
  sqlite3 *db;

public:
  xsqlite(std::string filename, sqliteopen flags = sqliteopen::rw);
  ~xsqlite();
};

inline sqliteopen operator|(sqliteopen dest, sqliteopen src) {
  return static_cast<sqliteopen>(static_cast<int>(dest) |
                                 static_cast<int>(src));
}
} // namespace xsqlite3