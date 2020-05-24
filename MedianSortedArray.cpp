#include <vector>
#include <iostream>
#include <map>

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {

    int size = nums1.size()+nums2.size();
        // if size is odd then mid = (size/2) + 1
        // else mid = size/2-1 and size/2
    double median = 0.0;
    int position = 0;
    int p_nums1 = 0;
    int p_nums2 = 0;
    while(position < size/2 + 1)
    {
        int value = 0;
        if(p_nums1 < nums1.size()&& p_nums2 < nums2.size())
        {
            if(nums1[p_nums1] < nums2[p_nums2])
            {
                value = nums1[p_nums1];
                p_nums1++;
            }
            else
            {
                value = nums2[p_nums2];
                p_nums2++;
            }
        }
        else if(p_nums2<nums2.size())
        {
                value = nums2[p_nums2];
                p_nums2++;
        }
        else
        {
            value = nums1[p_nums1];
            p_nums1++;
        }
        
        if(position == size/2-1 && size % 2 == 0)
        {
            median += (double)value;
        }
        
        if(position == size/2)
        {
            if(size%2 == 0)
                median = (median + (double)value)/2;
            else
                median = (double)value;
            
        }
        position++;
    }
    
    return median;
    }


int main()
{
    std::vector<int> a{1,3};  
    std::vector<int> b{2,4};  
    double d = findMedianSortedArrays(a,b); 
    std::cout << d  << std::endl;
}
   