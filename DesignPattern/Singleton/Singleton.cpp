#include <iostream>
#include <string>
using namespace std;
class database
{
private:
    static database *mInstancePtr;
    const static int iRecord = 6;
    string sName;
    database(string name)
    {
        sName = name;
    }

public:
    // void editRecord(int record)
    // {
    //     iRecord = record;
    // }
    string getName()
    {
        return sName;
    }
    static int getRecord()
    {
        return iRecord;
    }
    static database *startInstance(string name)
    {
        if (mInstancePtr == nullptr)
        {
            mInstancePtr = new database(name);
        }
        return mInstancePtr;
    }
};
database *database::mInstancePtr = nullptr;
// int database::iRecord = 5;
int main()
{
    database::startInstance("alo1");
    cout << database::getRecord();
    return 0;
}