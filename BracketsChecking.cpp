#include <string>
#include <stack>
#include <iostream>

using namespace std;

bool isValid(string s) {
        bool result = false;
        stack<char> st;
        st.push(' ');
        for(char c : s)
        {
            if(c == '[')
                st.push(']');
            else if(c == '(')
                st.push(')');
            else if(c == '{')
                st.push('}');
            else if(c == st.top())
                st.pop();
            else
                return false;
        }
        if(st.size()==1)
            return true;
        return result;
    }

int main()
{
    string s = "[";
    cout << (isValid(s)? "true":"false") << endl;
    return 0;
}