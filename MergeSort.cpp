#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

std::vector<int> merge(std::vector<int> a, std::vector<int> b)
{
    int size_a = a.size();
    int size_b = b.size();
    int lastchosen_a = 0;
    int lastchosen_b = 0;
    std::vector<int> result;
    while(lastchosen_a < a.size() && lastchosen_b < b.size())
    {
        if(a[lastchosen_a] <= b[lastchosen_b])
        {
            result.push_back(a[lastchosen_a]);
            lastchosen_a++;
        }
        else
        {
             result.push_back(b[lastchosen_b]);
             lastchosen_b++;
        }
    }

    while(lastchosen_b < b.size())
    {
        result.push_back(b[lastchosen_b]);
        lastchosen_b++;
    }
    while(lastchosen_a < a.size())
    {
        result.push_back(a[lastchosen_a]);
        lastchosen_a++;
    }
    return result;
    
}

void print_sort(int vecsize)
{
    int group_size = 2;
    
    std::cout << "vec.size() =>" << vecsize << std::endl; 
    while(group_size < vecsize)
    {
        int j = 0;
        int numgroups = vecsize/group_size + (vecsize%group_size>0?1:0);
        while(j < vecsize)
        {
            int residue = vecsize%(group_size/2);
            if(residue == 0)
            {
                
            }
        }
        std::cout << "\tnumber of groups =>" << numgroups;
        group_size = group_size*2;
    }
}
std::vector<int> sort(std::vector<int>& vec)
{
    int group_size = 1;
    int vec_size = vec.size();
    while(group_size <= vec_size)
    {
        std::vector<int> placeholder;
        for(int j = 0; j < vec_size; j = j+group_size*2)
        {
            int start = j;
            int mid = j + group_size;
            int end = j + group_size*2;
            std::vector<int> a;
            std::vector<int> b;
            a.insert(a.begin(),vec.begin()+start,vec.begin()+mid);
            std::cout << "1" << std::endl;
            std::cout << end << "\t, " << vec_size << std::endl;
            if(end < vec_size)
                b.insert(b.begin(),vec.begin()+mid,vec.begin()+end);
            else
                b.insert(b.begin(),vec.begin()+mid,vec.end());
            std::cout << "2" << std::endl;
            std::vector<int> sorted = merge(a,b);
            std::cout << "3" << std::endl;
            placeholder.insert(placeholder.begin()+start,sorted.begin(),sorted.end());
            std::cout << "4" << std::endl;
        }
        vec = placeholder;
        group_size = group_size*2;
    }
}

void randomArray(int size, int max, std::vector<int>& result)
{
    srand(time(NULL));
    for(int i = 0; i < size; ++i)
    {
        int k = rand() % max + 1;
        result.push_back(k);
    }
}

int main()
{
    std::vector<int> a;
    randomArray(6,10,a);
    print_sort(6);

    return 0;
}