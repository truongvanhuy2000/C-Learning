#include<gtest/gtest.h>
testing::AssertionResult IsEven(int n) {
  if ((n % 2) == 0)
    return testing::AssertionSuccess();
  else
    return testing::AssertionFailure() << n << " is odd";
}

TEST(AssertionResult, evenOdd)
{
    EXPECT_TRUE(IsEven(3));
}