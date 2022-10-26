#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = INT_MIN;int prefix_sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            prefix_sum+= nums[i];
            if(sum < prefix_sum) sum = prefix_sum;
            if(prefix_sum < 0) prefix_sum = 0;
        }

        return sum;
    }
};

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        vector<int> dp(nums);
        for(int i = 1;i < dp.size();i++)
        {
            dp[i] = max(nums[i],nums[i] + dp[i-1]);
        }
    
        int sum = dp[0];
        for(int i = 0;i<dp.size();i++)
        {
            sum = max(sum,dp[i]);
        }
        
        return sum;
    }
};