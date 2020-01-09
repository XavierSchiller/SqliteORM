#include "query.hpp"
#include "xsqlite3.hpp"
#include <iostream>

int
main()
{
  xsqlite3::xsqlite cl("chinook.db");

  xsqlite3::Record rs = cl.execute("SELECT * FROM albums;");
  rs.next();
  std::cout << rs.get<int>(0);
}