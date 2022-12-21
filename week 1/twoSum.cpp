#include "bits/stdc++.h"
using namespace std;

// In this problem, we will have created a hash map, 
// which will store all the values that are in array
// Now for each iteration, 
// we will check that complement of array element,i.e., target-nums[i], exist in hashmap, 
// if yes, we will give it as a result. 
// Otherwise, we will push the array element in the hash map and 
// move to the next element 

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> check;
        int n = nums.size();
        vector<int> sol;

        for (int i = 0; i < n; i++)
        {
            int comp = target - nums[i];
            if (check[comp] != 0)
            {
                sol.push_back(i);
                sol.push_back(check[comp] - 1);
                return sol;
            }

            check[nums[i]] = i + 1;
        }

        return sol;
    }
};