#include <iostream>
#include <string>
#include <cmath>

 int myAtoi(std::string x) {
    int v = 0;
    bool negate = false;
    int i = 0; 
    while(x[i] == ' ')
    {
        ++i;
        std::cout << "stuck in loop" << std::endl;
    }
    if(x[i] == '-')
    {
        negate = true;
        ++i;
    }
    else if(x[i]== '+')
    {
        ++i;
    }
    else if((int)x[i] < 58 && (int)x[i] > 47){}
    else
    {
        return 0;
    }
    while(i < x.size())
    {
        if((int)x[i] < 58 && (int)x[i] > 47)
        {
            
            if(negate && v > 214748364)
            {
                return -2147483648;
            }
            else if(v > 214748364)
            {
                return 2147483647;
            }
            v = v * 10;
            v = v + ((int)x[i] - 48);
        }
        else
        {
            break;
        }
        ++i;
    }
    if(negate)
    {
        v = -v;
    }
        return v;
    }


int main()
{
    std::string x = "42";
    std::cout << myAtoi(x);
    return 0;

}