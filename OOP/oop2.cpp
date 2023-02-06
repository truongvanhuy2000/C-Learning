#include <iostream>
class mother
{
    public:
    void display()
    {
        std::cout<<"im mother"<<std::endl;
    }
};
class daughter : public mother
{
    public:
    void display()
    {
        std::cout<<"im daughter"<<std::endl;
    }
};
int main()
{
    daughter dau1;
    dau1.display();
    return 0;
}