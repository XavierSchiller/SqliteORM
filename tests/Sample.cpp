#include "any.hpp"
#include "xsqlite3.hpp"
#include "query.hpp"
#include <iostream>
#include<typeinfo>
int main() {
  xsqlite3::xsqlite cl("Abestos.sqlite3");


  cl.begin_transaction();
  cl.execute("DELETE FROM MATCHES");
  cl.execute("INSERT INTO MATCHES VALUES(100,'200',100.0)");
  cl.execute("INSERT INTO MATCHES VALUES(100,'200',100.0)");
  cl.execute("INSERT INTO MATCHES VALUES(100,'200',100.0)");
  cl.execute("INSERT INTO MATCHES VALUES(100,'200',100.0)");
  cl.execute("INSERT INTO MATCHES VALUES(100,'200',100.0)");
  cl.execute("INSERT INTO MATCHES VALUES(100,'200',100.0)");
  cl.execute("INSERT INTO MATCHES VALUES(100,'200',100.0)");
  cl.execute("INSERT INTO MATCHES VALUES(100,'200',100.0)");
  cl.execute("INSERT INTO MATCHES VALUES(100,'200',100.0)");
  cl.commit_transaction();
  xsqlite3::Query a("$$$$");

  a.bind(1,"Something");

  std::cout << a.to_string();

  cl.execute("SELECT * FROM MATCHES");
  std::cout << cl.get_data<int>(0,0);
}