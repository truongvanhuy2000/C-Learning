#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
#define C_WORD 'a'
int TimSoLanXuatHien(vector<int> array)
{
    int i_count = 0;
    vector<int>::iterator p_data;
    p_data = array.begin();
    for(int i = 0; i < array.size(); i++)
    {
        if(*p_data == C_WORD)
        {
            i_count++;
        }
        p_data++;
    }
    return i_count;
} 
int main()
{  
    vector<int> v_data_array = {'a', 'b', 'c', 'a', 'a'};
    cout<< TimSoLanXuatHien(v_data_array)<< endl;
    return 0;
}