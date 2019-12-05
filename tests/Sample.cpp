#include "any.hpp"
#include "query.hpp"
#include "xsqlite3.hpp"
#include <iostream>
#include <typeinfo>
#include <vector>

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

  cl.execute({"INSERT INTO MATCHES VALUES(100,'200',100.0)",
              "INSERT INTO MATCHES VALUES(100,'200',100.0)"});
  cl.execute("INSERT INTO TEST VALUES(100,100,100,100,100,100)");


  cl.commit_transaction();
  cl.execute("SELECT * FROM MATCHES");

  auto v = cl.get_data_record<int,const char *,double>(0);

  std::cout<< std::get<1>(v);
}