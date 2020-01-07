#include "query.hpp"
#include "xsqlite3.hpp"
#include <iostream>
#include <typeinfo>
#include <vector>

int main() {
  xsqlite3::xsqlite cl("Abestos.sqlite3");

  xsqlite3::Record rs = cl.execute("SELECT * FROM MATCHES;");

  std::cout << rs.col_num();
}