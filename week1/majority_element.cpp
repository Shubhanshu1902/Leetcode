#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> count;
        int n = nums.size();
        int max_value = n/2;

        for(int i = 0;i < n;i ++)
        {
            if(count.find(nums[i]) == count.end())
                count[nums[i]] = 1;
            else count[nums[i]]++;

            if(count[nums[i]] > max_value) return nums[i];
        } 

        return -1;      
    }
};