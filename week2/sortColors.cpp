#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        auto a = nums.begin(),b = a,c = nums.end()-1;
        while (b<=c){
            if(*a == 0) b = ++a;
            else if(*c == 2) c--;
            else if(*b == 0) swap(*b,*a++);
            else if(*b == 2) swap(*b,*c--);
            else b++;
        }   
    }
};