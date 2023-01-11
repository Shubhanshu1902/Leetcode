#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> res;

    void sol(vector<int> nums, int i, vector<int> temp)
    {
        temp.push_back(nums[i]);
        nums.erase(nums.begin() + i);

        if (nums.empty())
        {
            res.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            sol(nums, i, temp);
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<int> temp;
        for (int i = 0; i < nums.size(); i++)
        {
            sol(nums, i, temp);
            temp.clear();
        }

        return res;
    }
};