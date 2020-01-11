#pragma once
#include "sqlite3/sqlite3.h"

namespace xsqlite3 {

enum sqliteopen
{
  read = SQLITE_OPEN_READONLY,
  write = SQLITE_OPEN_READWRITE,
  rw = SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE,
  create = SQLITE_OPEN_CREATE,
  nom = SQLITE_OPEN_NOMUTEX,
  fullm = SQLITE_OPEN_FULLMUTEX,
  ouri = SQLITE_OPEN_URI,
  scache = SQLITE_OPEN_SHAREDCACHE,
  pcache = SQLITE_OPEN_PRIVATECACHE
};

inline sqliteopen
operator|(sqliteopen dest, sqliteopen src)
{
  return static_cast<sqliteopen>(static_cast<int>(dest) |
                                 static_cast<int>(src));
}

enum sqlite_column_types
{
  integer,
  longinteger,
  floating,
  doublep,
  blob,
  null,
  text
};

} // namespace xsqlite3