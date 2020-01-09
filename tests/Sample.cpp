#include "query.hpp"
#include "xsqlite3.hpp"
#include <iostream>

int
main()
{
  xsqlite3::xsqlite cl("Abestos.sqlite3");

  std::string que = "Insert into tester values(100,'asdasdasd',0123123.2322);";

  std::cout << cl.execute_update(que);
}