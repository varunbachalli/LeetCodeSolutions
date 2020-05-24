#include <string>
#include <iostream>

int strStr(std::string haystack, std::string needle) {
        int needlesize = needle.size();
        if(needlesize == 0)
        {
            return 0;
        }
        for(int i = 0; i < haystack.size(); ++i)
        {
            std::string window = haystack.substr(i,needlesize);
            if(window == needle)
            {
                return i;
            }
            if(i == haystack.size() - needlesize)
            {
                break;
            }
        }
        return -1;
    }

int main()
{
    std::cout << strStr("", "a");
    return 0;
}