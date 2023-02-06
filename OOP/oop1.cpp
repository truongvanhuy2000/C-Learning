#include <iostream>
class shape
{
    public:
    shape(int a,int b)
    {
        width = a;
        height = b;
    }
    protected:
    int width;
    int height;
};
class triangle : public shape
{
    public:
    triangle(int a,int b):shape(a,b){};
    void size(void)
    {
        area = (width * height)/2;
        std::cout<<"area is "<<area<<std::endl;
    }
    protected:
    int area;
};
class rectangle : public shape
{
    public:
    rectangle(int a,int b):shape(a,b){};
    void size(void)
    {
        area = width * height; 
        std::cout<<"area is "<<area<<std::endl;
    }
    protected:
    int area;    
};
int main()
{
    triangle triangle1(10,15);
    rectangle rectangle1(5,6);
    triangle1.size();
    rectangle1.size();
    return 0;
}