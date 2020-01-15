#pragma once
#include "sqlite3.h"

namespace xsqlite3 {

/**
 * @brief Flag Enumerations for File open and closing.
 * 
 */
enum SqliteOpen
{
  eRead = SQLITE_OPEN_READONLY,
  eWrite = SQLITE_OPEN_READWRITE,
  eReadWrite = SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE,
  eCreate = SQLITE_OPEN_CREATE,
  eNoMutex = SQLITE_OPEN_NOMUTEX,
  eFullMutex = SQLITE_OPEN_FULLMUTEX,
  eURI = SQLITE_OPEN_URI,
  eSharedCache = SQLITE_OPEN_SHAREDCACHE,
  ePrivateCache = SQLITE_OPEN_PRIVATECACHE
};

inline SqliteOpen
operator|(SqliteOpen dest, SqliteOpen src)
{
  return static_cast<SqliteOpen>(static_cast<int>(dest) |
                                 static_cast<int>(src));
}

enum SqliteColumnTypes
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