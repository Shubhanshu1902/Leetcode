#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(),m = t.size();
        if(m >  n) return "";
        if(n == m && s == t) return s;
        if(n == m) return "";

        unordered_map<char,int> count;
        int l = 0;int r = 0;
        for(auto x : t) count[x]++;
        int min_win = INT_MAX;
        string res = "";

        while(r < n){
            if(count.find(s[r]) == count.end()) {r++;continue;}
            count[s[r]]--;
            m--;
            if(m == 0){
                while(count[s[l]]<0) count[s[l++]]++;
                int len = r - l;
                if(len < min_win){
                    min_win = len;
                    res = s.substr(l,len);
                }
                count[l]++;l++;
            }
            r++;
        }   

        return res;
    }
};