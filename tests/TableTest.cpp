#include "table.hpp"
#include <iostream>

int ttry(xsqlite3::table *arg) {
  xsqlite3::record *z = arg->get_record_at(0);

  std::cout << z->get_data<int>(0) << std::endl;
}

int main() {
  xsqlite3::table x;

  xsqlite3::record y;

  int test = 5;
  y.input_data(&test);

  x.input_record(&y);

  ttry(&x);
}