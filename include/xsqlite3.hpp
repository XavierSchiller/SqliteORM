#pragma once
#include "sqlerror.hpp"
#include <iostream>
#include <sqlite3.h>
#include <string>
#include <vector>
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
  union {
    const unsigned char *cdata;
    int idata;
    long int ldata;
    float fdata;
    double ddata;
  } d;
  void operator=(int x) {
    this->d.idata = x;
    this->type = sqlite_column_types::integer;
  };
  void operator=(float x) {
    this->d.fdata = x;
    this->type = sqlite_column_types::floating;
  };
  void operator=(double x) {
    this->d.ddata = x;
    this->type = sqlite_column_types::doublep;
  };
  void operator=(const unsigned char *x) {
    this->d.cdata = x;
    this->type = sqlite_column_types::text;
  };
  void operator=(long int x) {
    this->d.ldata = x;
    this->type = sqlite_column_types::longinteger;
  };

  template<typename T>
  T operator=(data d){
    switch (d.type)
    {
    case sqlite_column_types::integer : return d.d.idata;
    
    case sqlite_column_types::doublep: return d.d.ddata;
    
    case sqlite_column_types::floating : return d.d.fdata;
    
    case sqlite_column_types::longinteger : return d.d.ldata;
    
    case sqlite_column_types::text : return d.d.cdata;
    }
  }
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