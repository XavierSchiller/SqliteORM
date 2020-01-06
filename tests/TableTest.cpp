#include "table.hpp"
#include <iostream>
int ttry(xsqlite3::table arg) {
  xsqlite3::record *z = arg.get_record_at(0);

  std::cout << z->get_data<int>(0) << std::endl;
}

xsqlite3::table get() {
  xsqlite3::table x;
  xsqlite3::record *y;
  y = new xsqlite3::record;

  y->input_data(5);
  y->input_data(6);
  y->input_data("HAHAHSDHASD");
  x.input_record(y);

  return x;
}

int main() {
  xsqlite3::table x = get();
  ttry(x);
}