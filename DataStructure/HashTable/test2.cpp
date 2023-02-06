#include <iostream>
#include <unordered_map>
#include <iterator>
using namespace std;
int main()
{
    unordered_map<int, int> uMap;
    unordered_map<int, int>::iterator ptr;
    uMap[1] = 1;
    uMap[2] = 2;
    uMap[1] = 3;
    uMap[4] = 4;
    uMap[1] = 5;
    uMap[6] = 6;
    uMap[5] = 7;
    uMap[1] = 8;
    ptr = uMap.find(1);
    cout << ptr->second;
}