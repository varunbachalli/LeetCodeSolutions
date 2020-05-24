#include <iostream>
#include <string>
#include <map>
#include <iterator>

struct mapStruct
{
    int position = -1;
    std::map<int, char>::iterator itr;
};

mapStruct findPosition(std::map<int,char>& map, char c)
{
    mapStruct x;
    for(x.itr = map.begin(); x.itr!= map.end(); ++x.itr)
    {
        if(x.itr->second == c)
        {
            x.position = x.itr->first;
            ++x.itr;
            break;
        }
    }
    return x;
}
// int main()
// {

//     std::string s;
//     std::cin>> s;
//     std::map<int,char> characters;
    
//     int length =0;
//     int lengthMax = 0;
//     for(int i = 0; i < s.size(); ++i)
//     {
//         mapStruct x = findPosition(characters,s[i]); 
              
//         if(x.position == -1)
//         {   
//             characters[i] = s[i];
//             length++; 
//         }

//         else
//         {
//             if(length > lengthMax)
//             {
//                 lengthMax = length;
//             }
//             length++;
//             length = i - x.position;
//             characters.erase(characters.begin(),x.itr);
//             characters[i] = s[i];
//         }
//         for(auto itr2 = characters.begin(); itr2!= characters.end(); itr2++)
//         {
//             std::cout<< itr2->second << ",\t";
//         }
//         std::cout << std::endl;
//     }
    
//     std::cout << lengthMax;


//     return 0;
// }

int main()
{
    std::string s;
    std::cin >> s;
    std::map<char,int> characters;
    int maxLength = 0;
    bool repetitionfound = false;
    int lastchecked = -1;
    for(int i = 0; i < s.size();++i)
    {
        auto itr = characters.find(s[i]);
        if(itr!= characters.end())
        {
            
            if(i - itr->second > maxLength)
            {
                maxLength = i - itr->second;
                std::cout << i << "\t " << itr->second << std::endl;
                std::cout << "max length updated " << maxLength << std::endl; 
            }
            itr->second = i;
            lastchecked = itr->second;
            std::cout << "lastchecked  " << lastchecked << std::endl;
            repetitionfound = true;
        }
        else
        {
            characters[s[i]] = i;
            if(!repetitionfound)
                maxLength++;
        }

        if(i == s.size()-1 && i - lastchecked> maxLength)
        {
            std::cout << "i- lastchecked  "<< i << "," << lastchecked << std::endl;
            maxLength = i - lastchecked;
        }

        for(auto it = characters.begin(); it !=characters.end();++it)
        {
            std::cout << it->first << "\t,\t" << it->second << "\t";
        }
        std::cout << "maxLength - " << maxLength << std::endl;
    }
    std::cout << maxLength << std::endl;
}




