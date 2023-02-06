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
                std::cout << "not prime" << std::endl;
                return false;
            }
        }
        std::cout << "is prime" << std::endl;
        return true;
    }
    int sumOfPrimeNumber(int n)
    {
        if(isPrimeNumber(n))
        {
            return n + sumOfPrimeNumber(n - 1);
        }
        else
        {
            return 0;
        }
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
TEST_F(PrimeNumberFixture, isPrime)
{
    bool result;
    result = prime->isPrimeNumber(17);
    EXPECT_EQ(result, true);
}
TEST_F(PrimeNumberFixture, sum)
{
    int result;
    result = prime->sumOfPrimeNumber(7);
    EXPECT_EQ(result, 18);
}




