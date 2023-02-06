#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int tinhTongSoChan(vector<int>::iterator ptr, int length)
{
    if(length > 0)
    {
        int s = tinhTongSoChan(ptr + 1, length - 1);
        if(*ptr % 2 == 0)
        {
            return(*ptr + s);
        }
        else
        {
            return s;
        }
    }
    return 0;
}
int main()
{
    vector<int> mang = {1, 2, 4, 6, 7, 9, 10, 20, 45, 66};
    cout<< tinhTongSoChan(mang.begin(), mang.size())<< endl;
    return 0;
}