#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
    stack<long long int> minstack;
    long long int mini = INT_MAX;

    MinStack() {}

    void push(long long int val)
    {
        if (minstack.empty())
        {
            minstack.push(val);
            mini = val;
        }
        else if (val < mini)
        {
            minstack.push(2*val*1LL - mini);
            mini = val;
        }
        else{
            minstack.push(val);
        }
    }

    void pop()
    {
        long long int a = minstack.top();
        minstack.pop();
        if(a < mini){
            mini = 2*mini - a;
        }
    }

    long long int top()
    {
        long long int a = minstack.top();
        if(a < mini) return mini;
        return a;
    }

    long long int getMin()
    {
        return mini;
    }
};