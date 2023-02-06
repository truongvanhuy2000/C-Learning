#include <iostream>
#include <string>
using namespace std;
enum eTransportationType
{
    Truck,
    Ship,
    Airplane,
    Boat,
    Helicopter,
    Car
};
class iTransportMethod
{
public:
    virtual void transport() = 0;
};
class AirplaneClass : public iTransportMethod
{
public:
    void transport()
    {
        cout << "hey im airplane" << endl;
    }
};
class HelicopterClass : public iTransportMethod
{
public:
    void transport()
    {
        cout << "hey im helicopter" << endl;
    }
};
class ShipClass : public iTransportMethod
{
public:
    void transport()
    {
        cout << "hey im ship" << endl;
    }
};
class BoatClass : public iTransportMethod
{
public:
    void transport()
    {
        cout << "hey im boat" << endl;
    }
};
class TruckClass : public iTransportMethod
{
public:
    void transport()
    {
        cout << "hey im truck" << endl;
    }
};
class CarClass : public iTransportMethod
{
public:
    void transport()
    {
        cout << "hey im car" << endl;
    }
};
class iLogistic
{
public:
    virtual iTransportMethod *createTransport(eTransportationType type) = 0;
};
class seaLogistic : public iLogistic
{
public:
    iTransportMethod *createTransport(eTransportationType type)
    {
        switch (type)
        {
        case Ship:
            return new ShipClass();
            break;
        case Boat:
            return new BoatClass();
            break;
        default:
            break;
        }
    }
};
class landLogistic : public iLogistic
{
public:
    iTransportMethod *createTransport(eTransportationType type)
    {
        switch (type)
        {
        case Truck:
            return new TruckClass();
            break;
        case Car:
            return new CarClass();
            break;
        default:
            break;
        }
    }
};
class airLogistic : public iLogistic
{
public:
    iTransportMethod *createTransport(eTransportationType type)
    {
        switch (type)
        {
        case Airplane:
            return new AirplaneClass();
            break;
        case Helicopter:
            return new HelicopterClass();
            break;
        default:
            break;
        }
    }
};
int main()
{
    iLogistic *logistic1 = new airLogistic();
    iTransportMethod *transport1 = logistic1->createTransport(Airplane);
    transport1->transport();
    iLogistic *logistic2 = new seaLogistic();
    iTransportMethod *transport2 = logistic2->createTransport(Ship);
    transport2->transport();
    iLogistic *logistic3 = new landLogistic();
    iTransportMethod *transport3 = logistic3->createTransport(Truck);
    transport3->transport();
    return 0;
}