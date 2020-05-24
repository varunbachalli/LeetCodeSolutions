#include <vector>
#include <iostream>
 bool checkPossibility(std::vector<int>& nums) {
    
    bool forgiven_once = false;
    for(int i = 2; i < nums.size();++i)
    {
        int a = nums[i-2]; 
        int b = nums[i-1];
        int c = nums[i];

        if(a <= b && b <= c)
        {
            std::cout << "stage 1\t" << a << ", " << b << ", " << c << std::endl;
            continue;
        }
        
        else if(a >= b && b <= c)
        {
            std::cout << "stage 2\t" << a << ", " << b << ", " << c << std::endl;
            if(forgiven_once == false)
                forgiven_once = true;
            else
                return false;
            if(c<= a)
                nums[i-2] = nums[i-1];
            else
                nums[i-1] = nums[i-2];
            
        }

        else if(a <= b && b >= c)
        {
            std::cout << "stage 3\t" << a << ", " << b << ", " << c << std::endl;
            if(forgiven_once == false)
                forgiven_once = true;
            else
                return false;

            if(c >= a)
                nums[i-1] = nums[i-2];
            else
                nums[i] = nums[i-1];
            
        }

        else // a > b && b > c
        {
            std::cout << "stage 4\t" << a << ", " << b << ", " << c << std::endl;
            return false;
        }
    }

    return true;
     
 }

int main()
{
    std::vector<int> a{1,1,1};
    bool poss = checkPossibility(a);
    std::cout <<" final result " <<  poss << std::endl;
    return 0;
}


/*
idea : 
check the first 3 elements. 
if the second one has a value less than the first one, 
and third one has a value less than that of the second one. Then break automatically and return false
Else
the c value is 
*/