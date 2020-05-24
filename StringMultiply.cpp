#include <string>
#include <iostream>
using namespace std;

string multiply(string nums1, string nums2) 
{
    int result = 0;
    int intermediate = 0;
    for(int i = nums1.size()-1; i >= 0; --i)
    {
        result = result*10;
        intermediate = 1;
        for(int j = nums2.size()-1; j >= 0; --j)
        {
            intermediate = (int)(nums2[j] - 48)*pow(10,nums2.size()-j);
            intermediate+=(int)(nums1[i] - 48) * (int)(nums2[j] - 48);
        }
    }
}

int main()
{
    string k = multiply("312","20");
    if(k == to_string(312*20))
    {
        cout << "worked fine" << endl;
    }
}

