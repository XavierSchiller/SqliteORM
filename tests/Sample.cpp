#include "any.hpp"
#include "xsqlite3.hpp"
#include <iostream>
int main() {
  xsqlite3::xsqlite cl("Abestos.sqlite3");

  cl.execute("SELECT * FROM MATCHES");
}