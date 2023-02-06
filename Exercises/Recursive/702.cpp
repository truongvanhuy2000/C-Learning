#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int tinhTong(int n)
{
    if(n >= 0)
    {
        return(n + tinhTong(n - 1));
    }
    return 0;
}
int main()
{
    cout<< tinhTong(3)<< endl;
    return 0;
}
