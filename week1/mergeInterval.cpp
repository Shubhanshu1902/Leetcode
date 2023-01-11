#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(),intervals.end());

        int n=intervals.size();
        int j=0;

        vector<vector<int>> merged;
        int k=-1;
        while(j<n)
        {
            if(k==-1 || merged[k][1]<intervals[j][0])
            {
                merged.push_back(intervals[j]);
                k++;
            }

            else
            {
                merged[k][1]=max(intervals[j][1],merged[k][1]);
            }
            j++;

        }

        return merged;
    }
};