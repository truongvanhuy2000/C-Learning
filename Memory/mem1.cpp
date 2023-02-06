#include <iostream>

class Foo {
public:
    Foo( void )
    { std::cout << "Foo constructor 1 called" << std::endl; }
    ~Foo( void)
    { std::cout << "Foo destructor 1 called" << std::endl;}
};

int main( )
{
    Foo foo_1;
    delete &foo_1;
    return 0;
}