#include <iostream>
#include <vector>
#include <iterator>
#include<math.h>
using namespace std;
int TinhBieuThuc(int x, int n)
{
    int s;
    if(n == 0)
    {
        return 1;
    }
    s = n * TinhBieuThuc(x, n - 1);
    return(x + pow(x, n)/s);
}
int main()
{
    cout<< TinhBieuThuc(10, 2)<< endl;
    return 0;
}