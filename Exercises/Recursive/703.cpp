#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int tinhTich(int n)
{
    if(n == 0)
    {
        return 1;
    }
    else if(n > 0)
    {
        return(n * tinhTich(n - 1));
    }
    return 0;
}
int main()
{
    cout<< tinhTich(4)<< endl;
    return 0;
}