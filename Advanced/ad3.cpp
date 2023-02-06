#include <iostream>
using namespace std;
template <class T>
class table
{
    public:
    table(int n_elem)
    {
        T *mang = new T[n_elem];
        for(int i = 0; i < n_elem;i++)
        {
            cout << mang[i] << endl;
        }
    }
    private:
    T *mang;
};
int main( )
{
    //table<int> table_int(5);
    table<char> table_float(10);
    return 0;
}