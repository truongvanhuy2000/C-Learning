#include <iostream>
#include<cstring>
using namespace std;
enum scheme
{
    RGB_Color,
    HSB_Color,
    CMYK_Color
};
class colorScheme
{
    public:
    virtual void makeColor(float* value, int size) = 0;
};
class rgbColor : public colorScheme
{
    public:
    void makeColor(float* value, int size)
    {
        if(size != 3)
        {
            cout << "wrong value" << endl;
            return;
        }
        cout << "red: " << value[0] << " green: " << value[1] << " blue: " << value[2] << endl;
    }
};
class hsbColor : public colorScheme
{
    public:
    void makeColor(float* value, int size) 
    {
        if(size != 3)
        {
            cout << "wrong value" << endl;
            return;
        }
        cout << "hue: " << value[0] << " saturation: " << value[1] << " brightness: " << value[2] << endl;
    }
};
class cmykColor : public colorScheme
{
    public:
    void makeColor(float* value, int size)
    {
        if(size != 4)
        {
            cout << "wrong value" << endl;
            return;
        }
        cout << "cyan: " << value[0] << " magenta: " << value[1] << " yellow: " << value[2] << " black: " << value[3] << endl;
    }
};
class colorFactory
{
    public:
    static colorScheme* getColor(scheme Scheme)
    {
        if(Scheme == RGB_Color) return new rgbColor();
        else if(Scheme == HSB_Color) return new hsbColor();
        else if(Scheme == CMYK_Color) return new cmykColor();
        else return nullptr;
    }
};
int main()
{
    colorScheme* color1;
    color1 = colorFactory::getColor(CMYK_Color);
    float arr[] = {20, 30, 40, 50};
    color1->makeColor(arr, sizeof(arr)/sizeof(float));
}