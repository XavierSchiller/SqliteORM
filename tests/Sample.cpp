#include "any.hpp"
#include "xsqlite3.hpp"
#include <iostream>
int main() {
  xsqlite3::xsqlite cl("Abestos.sqlite3");

  cl.execute("SELECT * FROM MATCHES");

	std::cout << any_cast<int>(cl.result.at(0).element.at(0).d);
}