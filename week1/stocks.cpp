#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_val = 0;
        int curr = prices[0];
        for(int i = 0;i < prices.size();i++)
        {
            if(curr > prices[i])
            {
                curr = prices[i];
            }

            else{
                max_val = max(max_val,prices[i] - curr);
            }
        }

        return max_val;
    }
};