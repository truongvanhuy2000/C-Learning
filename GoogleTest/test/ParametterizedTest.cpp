#include<iostream>
#include<gtest/gtest.h>
class PrimeNumber
{
    public:
    PrimeNumber(){};
    ~PrimeNumber(){};
    bool isPrimeNumber(int x)
    {
        for(int i = 2; i <= x/2; ++i)
        {
            if(x % i == 0)
            {
                return false;
            }
        }
        return true;
    }
};
class PrimeNumberFixture : public :: testing :: Test
{
    protected:
    PrimeNumber *prime;
    void SetUp() override
    {
        prime = new PrimeNumber();
    }
    void TearDown()
    {
        delete prime;
    }
};
class PrimeNumberParameterTest : public PrimeNumberFixture, public ::testing::WithParamInterface<int>{};

TEST_P(PrimeNumberParameterTest, IsPrimeCheck)
{
    int number = GetParam();
    EXPECT_TRUE(prime->isPrimeNumber(number));
}
INSTANTIATE_TEST_SUITE_P(PrimeTesting,
                         PrimeNumberParameterTest,
                         testing::Values(5, 7, 13, 15, 18));

