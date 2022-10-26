#include "bits/stdc++.h"
using namespace std;

/*
In this problem, we are using a stack for validation. We are storing every opening bracket in stack and if the closing
bracket matches with the stack top, we will remove the top. If not we will return false
*/
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> paranthesis;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') paranthesis.push(s[i]);
            else{
                if(paranthesis.empty()) return false;
                if(s[i] == ')' && paranthesis.top() == '(' || 
                    s[i] == ']' && paranthesis.top() == '[' ||
                    s[i] == '}' && paranthesis.top() == '{' ) 
                    paranthesis.pop();

                else return false;
            }
        }

        if (paranthesis.empty())
            return true;
        else
            return false;
    }
};