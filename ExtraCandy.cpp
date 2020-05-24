#include <vector>
#include <iostream>
std::vector<bool> kidsWithCandies(std::vector<int>& a, int extraCandies) 
{   
    int max = 0;
    for(int i : a)
    {
        if(i > max)
        {
            max = i;
        }
    }
    std::vector<bool> results;
    for(int i : a)
    {
        if(extraCandies + i >= max)
            results.push_back(true);
        else
            results.push_back(false);
    }
    return results;
}
int main()
{
    std::vector<int> a{1,2,3,4,5};
    std::vector<bool> results = kidsWithCandies(a,2);
    for(bool x : results)
    {
        std::cout << (x?"true , ":"false ,") << std::endl;
    }
    return 0;
}