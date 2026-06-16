//
// Created by Karan Nandkar on 10/05/26.
//

#include <stack>
#include <string>
#include <unordered_map>

bool IsValid(const std::string& s)
{
    std::stack<char> st;
    std::unordered_map<char, char> brackets = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

    for (char c : s)
    {
        // opening brackets
        if (c == '(' || c == '[' || c == '{')
        {
            st.push(c);
        }
        else
        {
            // Invalid: no opening bracket
            if (st.empty())
            {
                return false;
            }

            // Invalid: mismatch
            if (st.top() != brackets[c])
            {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

bool IsValidOptimized(const std::string& s)
{
    std::stack<char> st;
    for (char c : s)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            st.push(c);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }

            char top = st.top();
            if (c == ')' && top != '(' || c == ']' && top != '[' || c == '}' && top != '{')
            {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}
