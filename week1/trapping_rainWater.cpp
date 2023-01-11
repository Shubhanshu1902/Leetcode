#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int totalTrapped = 0;
        int l = 0,r = height.size()-1;
        int left_max = 0,right_max = 0;

        while(l < r){
            if(height[l] < height[r]){
                if(height[l] > left_max) left_max = height[l];
                else totalTrapped += (left_max - height[l]);
                l++;
            }
            else{
                if(height[r] > right_max) right_max = height[r];
                else totalTrapped += (right_max - height[r]);
                r--;
            }
        }

        return totalTrapped;
    }
};