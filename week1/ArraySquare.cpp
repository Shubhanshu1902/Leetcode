#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> output(n,1);
        int fromBeg = 1,fromEnd = 1;

        for (int i = 0;i < n; i++)
        {
            output[i]*=fromBeg;
            fromBeg*=nums[i];
            output[n-i-1] *= fromEnd;
            fromEnd *= nums[n-i-1];
        }

        return output;
    }
};