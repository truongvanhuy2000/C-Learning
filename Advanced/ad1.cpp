#include <iostream>

class complex_number 
{
    public:
    complex_number(double real = 0,double img = 0)
    {
        real_number = real;
        img_number = img;
    }
    complex_number operator+(const complex_number& b)
    {
        complex_number comp;
        comp.real_number = this->real_number + b.real_number;
        comp.img_number = this->img_number + b.img_number;
        return comp;
    }
    double get_real()
    {
        return real_number;
    }
    double get_img()
    {
        return img_number;
    }
    private:
    double real_number;
    double img_number;
};

int main( )
{
    complex_number comp1(15,20);
    complex_number comp2(20,30);
    complex_number comp3;
    comp3 = comp1 + comp2;
    std::cout<<"real: "<< comp3.get_real() << " img: "<< comp3.get_img() <<std::endl;
    return 0;
}