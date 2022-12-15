#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> count;
        for(auto i:s) count[i]++;
        int res = 0;

        for(auto i:count)
        {
            res += i.second/2*2;
            if(i.second%2 == 1 && res%2==0)   
                res++;
        }

        return res;
    }
};