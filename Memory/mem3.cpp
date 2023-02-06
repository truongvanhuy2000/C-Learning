#include <iostream>
class IntegerArray
{
    public:
    IntegerArray (int x)
    {
        index = x;
    }
    int index;
    int *data = new int[index];
};
int main() 
{
    IntegerArray a(2);//This call the constructor
    a.data[0] = 4; a.data[1] = 2;
    if (true) 
    {
        IntegerArray b = a;
    }
    std::cout << a.data[0] << std::endl; // The result is 4
}