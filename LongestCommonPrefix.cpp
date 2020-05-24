#include <vector>
#include <string>
#include <iostream>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        
        int position = 0;
        if(strs.size() == 1)
            return strs[0];
        if(strs.size() == 0)
            return prefix;
        else
        {
            while(position < strs[0].size())
            {
                bool have_common_letter = true;
                char commonletter = strs[0][position];
                for(int i = 1; i < strs.size(); ++i)
                {
                        if(strs[i].size() < position)
                        {
                            return prefix;
                        }
                    
                        have_common_letter = (have_common_letter && strs[i][position] == commonletter);
                        
                }
                if(!have_common_letter)
                {
                    return prefix;
                }
                prefix = prefix + commonletter;
                position++;
            }
        }
        
        return prefix;
        
    }

int main()
{
    vector<string> a{"pre", "pr"};
    string prefix = longestCommonPrefix(a);
    cout << prefix << endl;
    return 0;
}