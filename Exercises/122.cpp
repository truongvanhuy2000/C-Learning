#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
#define I_MAX 10 
int FindMax(vector<int> array)
{
    int i_max = 0;
    vector<int> :: iterator p_data = array.begin();
    for(int i = 0; i < array.size(); i++)
    {
        if(*p_data > i_max)
        {
            i_max = *p_data;
        }
        p_data++;
    }
    return i_max;
}
void NhapMang(vector<int>& array)
{
    int i_input_value = 0;
    for(int i = 0; i < I_MAX; i++)
    {
        cout<< "nhap so thu "<< i+1<< endl;
        cin>> i_input_value;
        array.push_back(i_input_value);
    }
}
int main()
{
    vector<int> v_mang;
    NhapMang(v_mang);
    cout<< "so lon nhat la "<< FindMax(v_mang)<< endl;
    return 0;
}