#include<iostream>
#include"xsqlite3.hpp"
int main()
{
	xsqlite3::xsqlite cl("Abestos.sqlite3");

	cl.execute("SELECT * FROM MATCHES");

	std::cout<< cl.result.at(0).element.at(0).d.idata;
}