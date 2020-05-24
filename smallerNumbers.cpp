#include<vector>
#include<iostream>
#include<map>

std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums) 
{
        
        std::map<int,int> results;
        std::vector<int> r;
        int rank =0;
        for(int i = 0; i < nums.size();++i)
        {
            results[nums[i]] = rank;
            for(auto itr = results.begin();itr!=results.end();itr++)
            {
                if(itr->first > nums[i])
                {
                    results[nums[i]] = itr->second;
                    itr->second = rank;
                }
                else if(itr->first == nums[i])
                {
                    results[nums[i]] = itr->second;
                    break;
                }
            }
            rank++;
        }

        for(auto itr = results.begin();itr!=results.end();itr++)
        {r.push_back(itr->second);}
        return r;
    }

int main()
{
    std::vector<int> a{8,1,2,2,3};
    std::vector<int> results = smallerNumbersThanCurrent(a);
    for(int i : results)
    {
        std::cout << i << "\t,";
    }
    std::cout << std::endl;
    return 0;
}