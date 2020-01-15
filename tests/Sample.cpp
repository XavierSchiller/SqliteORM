#include "xsqlite3.hpp"
#include "transaction.hpp"
#include "gtest/gtest.h"

class RecordTest : public ::testing::Test
{
protected:
  xsqlite3::Sqlite cl;
  RecordTest()
    : cl(":memory:")
  {}
  void SetUp() override
  {
    cl.ExecuteUpdate("Create table tester(a int, b text, c real);");
    cl.ExecuteUpdate(
      "Insert into tester values(100,'asdasdasd',123123.2322);");
  }
  void TearDown() override {}
};

TEST_F(RecordTest, RecordTest_ObtainInts_Test)
{
  auto rs = cl.Execute("select * from tester");
  EXPECT_EQ(rs.get<int>(0), 100);
}

TEST_F(RecordTest, RecordTest_ObtainsDoubles_Test)
{
  auto rs = cl.Execute("select * from tester");
  ASSERT_DOUBLE_EQ(rs.get<double>(2), 123123.2322) << rs.get<double>(2);
}

TEST_F(RecordTest, RecordTest_ObtainsString_Test)
{
  auto rs = cl.Execute("select * from tester");
  EXPECT_STRCASEEQ("asdasdasd", rs.get<std::string>(1).c_str());
}

TEST_F(RecordTest, RecordTest_Transaction_Basic)
{
  EXPECT_NO_THROW({
    xsqlite3::Transaction tx(cl);
    auto rs = tx.Execute("Select * from tester;");
    if(rs.get<int>(0) != 100)
      throw "AAA";
    int a = tx.ExecuteUpdate("Insert into tester values(100,'asdasdasd',123123.2322);");
    if(a != 1)
      throw "AAA";
  });
}

int
main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}