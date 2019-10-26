#include "any.hpp"
#include "xsqlite3.hpp"
#include <iostream>
#include<typeinfo>
int main() {
  xsqlite3::xsqlite cl("Abestos.sqlite3");

  cl.execute("INSERT INTO MATCHES VALUES(100,'200',100.0)");
  cl.execute("SELECT * FROM MATCHES");

  xsqlite3::Query a("$$$$");

  a.bind(1,"Something");

  std::cout << a.to_string();
}