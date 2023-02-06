#include <iostream>
void reader(const char *data)
{
    std::cout<<data<<std::endl;
}
void modifier(const char *data)
{
    for(int i = 0; i < 11; i++)
    {
        data[i] = '0';
    }
}
int main( )
{
    const char array[] = { 'L', 'e', ' ', 'T', 'r', 'a', 'n', ' ', 'D', 'a', 't'};
    reader(array);
    return 0;
}