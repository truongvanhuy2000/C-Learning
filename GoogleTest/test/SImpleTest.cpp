#include<gtest/gtest.h>
int Factorial(int n)
{
    if(n == 0)
    {
        return 1;
    }
    return n*(Factorial(n-1));
}
TEST(SimpleTest, HandlePositiveInput)
{
    //Arrange
    int range = 5;
    int result;
    //Act
    result = Factorial(range);
    //Assert 
    EXPECT_EQ(Result, 120);
}
