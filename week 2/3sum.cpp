#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        unordered_map<int, int> vls;
        sort(nums.begin(), nums.end());

        // Storing the index of number and avoiding all duplicates
        for (int i = 0; i < nums.size(); i++)
        {
            vls[nums[i]] = i;
        }

        int i = 0;
        while (i < nums.size())
        {
            int j = i + 1;
            while (j < nums.size())
            {
                int req_number = 0 - nums[i] - nums[j];
                // Smaller number than j
                if(req_number < nums[j]) break;
                // Same number
                if(req_number == nums[j] && j == vls[req_number]) break;
                
                if(vls.find(req_number) != vls.end()){
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(req_number);
                    ans.push_back(tmp);
                }

                j = vls[nums[j]] + 1;
            }

            i = vls[nums[i]] + 1;
        }

        return ans;
    }
};