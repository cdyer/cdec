#include "logval.h"

#include <gtest/gtest.h>
#include <iostream>

class LogValTest : public testing::Test {
 protected:
  virtual void SetUp() { }
  virtual void TearDown() { }
};

using namespace std;

TEST_F(LogValTest,Invert) {
  LogVal<double> x(-2.4);
  LogVal<double> y(2.4);
  y.invert();
  EXPECT_FLOAT_EQ(x,y);
}

TEST_F(LogValTest,Minus) {
  LogVal<double> x(12);
  LogVal<double> y(2);
  LogVal<double> z1 = x - y;
  LogVal<double> z2 = x;
  z2 -= y;
  EXPECT_FLOAT_EQ(z1, z2);
  EXPECT_FLOAT_EQ(z1, 10.0);
  EXPECT_FLOAT_EQ(y - x, -10.0);
}

TEST_F(LogValTest,TestOps) {
  LogVal<double> x(-12.12);
  LogVal<double> y(x);
  cerr << sizeof(LogVal<double>) << endl;
  cerr << sizeof(LogVal<float>) << endl;
  cerr << x << endl;
  cerr << (x*y) << endl;
  cerr << (x*y + x) << endl;
  cerr << (x + x*y) << endl;
  cerr << log1p(-0.5) << endl;
  LogVal<double> aa(0.2);
  LogVal<double> bb(-0.3);
  cerr << (aa + bb) << endl;
  cerr << (bb + aa) << endl;
  EXPECT_FLOAT_EQ((aa + bb), (bb + aa));
  EXPECT_FLOAT_EQ((aa + bb), -0.1);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

