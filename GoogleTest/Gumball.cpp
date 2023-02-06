#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include "Gumball.hpp"
using namespace std;

int main()
{
    int count = 5;
    GumballMachine gumballMachine1(100);
    while(count > 0)
    {
        cout << "time : " << count << endl;
        gumballMachine1.insertQuarter();
        gumballMachine1.turnCrank();
        count--;
    }
    return 0;
}