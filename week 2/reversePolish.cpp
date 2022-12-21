#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int evalRPN(vector<string> &tokens)
    {
        stack<long long int> vals;
        long long int out = 0;
        for (auto i : tokens)
        {
            if (i == "+")
            {
                long long int a = vals.top();
                vals.pop();
                long long int b = vals.top();
                vals.pop();
                vals.push(a + b);
            }

            else if (i == "-")
            {
                long long int a = vals.top();
                vals.pop();
                long long int b = vals.top();
                vals.pop();
                vals.push(b - a);
            }

            else if (i == "*")
            {
                long long int a = vals.top();
                vals.pop();
                long long int b = vals.top();
                vals.pop();
                vals.push(a * b);
            }

            else if (i == "/")
            {
                long long int a = vals.top();
                vals.pop();
                long long int b = vals.top();
                vals.pop();
                vals.push(b / a);
                // cout<<vals.top()
            }

            else{
                vals.push(stoi(i));
            }
        }

        return vals.top();
    }
};