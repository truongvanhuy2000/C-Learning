#include <iostream>

int main( )
{
    int x = 0;
    std::cout<< "nhap so phan tu mang"<<std::endl;
    std::cin >> x;
    int *mang = new int [x];
    std::cout<< "nhap cac phan tu:"<<std::endl;
    for(int i = 0; i<x ; )
    delete[] mang;
    return 0;
}