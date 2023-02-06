#include <iostream>
class animal
{
protected:
    char * animal_name;
    int animal_age;
public:
 void set_value(char * name,int age);
};
void animal::set_value(char* name,int age)
{
    animal_name = name;
    animal_age = age;
}
class zebra : public animal
{
    public:
    void print_info()
    {
        std::cout<<"animal name and age is "<<animal_name<<" and " <<animal_age<<std::endl;
    }
};
class dolphin  : public animal
{
    public:
    void print_info()
    {
        std::cout<<"animal name and age is "<<animal_name<<" and " <<animal_age<<std::endl;
    }
};
int main()
{
    zebra zeb1;
    dolphin dol1;
    zeb1.set_value((char*)"dit con",20);
    dol1.set_value((char*)"me may", 300);
    zeb1.print_info();
    dol1.print_info();
    return 0;
}