#include <string>
#include <iostream>


 bool buddyStrings(std::string A, std::string B) {
        std::string temp;
        if(A.size() == 0 || B.size()==0)
        {
            return false;
        }
        for(int i = 0; i < B.size()-1; ++i)
        {
            temp = B;
            char c;
            c = temp[i];
            temp[i] = temp[i+1];
            temp[i+1] = c;
            

            if(temp == A)
            {
                return true; 
            }
        }
        return false;
    }


int main()
{
    
    std::string x = "abcd";
    return 0;
}
