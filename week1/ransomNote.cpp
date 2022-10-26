#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> count;
        for(int i = 0;i<magazine.size();i++)
            count[magazine[i]]++;

        for(int i = 0;i<ransomNote.size();i++)
        {
            if(count[ransomNote[i]] == 0)
                return false;
            
            count[ransomNote[i]]--;
        } 

        return true;
    }
};