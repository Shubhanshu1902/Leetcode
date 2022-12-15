#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int m = s.size();
        int res = 0;
        unordered_map<char, int> contain;
        int len = 0;
        for (int i = 0; i < m; i++)
        {
            if (contain[s[i]] > 0)
            {
                len = max(contain[s[i]], len);
            }

            res = max(res,i - len + 1);
            contain[s[i]] = i + 1;
        }

        return res; 
    }
};