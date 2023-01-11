#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int coinChange(vector<long long int> &coins, long long int amount)
    {
        long long int max = amount + 1;
        vector<long long int> vals(max,INT_MAX);
        vals[0] = 0;

        for (long long int i = 0; i < max; i++)
        {
            for (long long int j = 0; j < coins.size(); j++)
            {
                if (coins[j] <= i)
                    vals[i] = min(vals[i],vals[i - coins[j]] + 1);
            }
        }

        if(vals[amount] > amount) return -1;
        else return vals[amount];
    }
};