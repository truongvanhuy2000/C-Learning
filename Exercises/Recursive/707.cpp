#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int Fibo(int n)
{
    if(n == 1)
    {
        return 1;
    }
    else if(n == 0)
    {
        return 0;
    }
    return(Fibo(n - 1) + Fibo(n - 2));
}
int main()
{
    cout<< Fibo(5)<< endl;
    return 0;
}