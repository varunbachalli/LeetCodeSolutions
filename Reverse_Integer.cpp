#include <cmath>
#include<iostream>
long reverse(int x)
{
    long ans = 0;
    for(int i = 0; i < 11; ++i)
    {
        int k = 2147483647;
        if(x%10 != 0 || x%k!=0)
        {
            ans = ans*10;
            if(ans > 2147483647)
            {
                return 0;
            }
            ans = ans + (x % 10);
            x = x/10;
        }
        else
            break;
    }
    if(ans*x < 0)
    {
        ans = -ans;
    }
        
    return ans;
}
int main()
{

    int x = -2147483648;
    std::cout << reverse(x) << std::endl;
    return 0;
}