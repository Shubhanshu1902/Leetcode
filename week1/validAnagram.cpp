#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> check;
        int cns = 0, cnt = 0;
        for (auto i : s)
        {
            if (i != ' ')
            {
                check[i]++;
                cns++;
            }
        }

        for (auto i : t)
        {
            if (!check[i] && i != ' ')
                return false;

            if (i != ' ')
            {
                check[i]--;
                cnt++;
            }
        }

        if(cns == cnt)
            return true;

        return false;
    }
};