#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int timSoDuong(vector<int>::iterator ptr, int length)
{
    if(length > 0)
    {
        int s = timSoDuong(ptr + 1, length - 1);
        if(*ptr > 0)
        {
            return(s + 1);
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
    vector<int> mang = {-1, -2, 4, 6, -7, 9, -10, 20, -45, 66};
    cout<< timSoDuong(mang.begin(), mang.size())<< endl;
    return 0;
}