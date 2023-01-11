#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1;
        while (n--)
        {
            b = b+a;
            a = b;
        }
        return b;
    }
};  