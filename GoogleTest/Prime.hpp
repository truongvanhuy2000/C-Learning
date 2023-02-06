#ifndef PRIME_HPP
#define PRIME_HPP
#include <iostream>
#include <string>
using namespace std;
class PrimeNumber
{
    public:
    PrimeNumber(){};
    ~PrimeNumber(){};
    virtual bool isPrimeNumber(int x)
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
    virtual int sumOfPrimeNumber(int n)
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
#endif