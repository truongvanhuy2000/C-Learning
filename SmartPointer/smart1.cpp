#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;
class Car
{
public:
    virtual int price() = 0 ;
    virtual string brand() = 0 ;
};

class Interface
{
public:
    virtual Car* giveMeACar() = 0 ;
    virtual Car* listMeAllTheCars() = 0 ;
};
int main()
{
    return 0;
}