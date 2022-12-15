#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Store the distance of each point
    // Then sort these points 
    // get first k elements from sorted arrays
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        vector<vector<int,int>> dis;
        int j = 0;
        for(int i = 0;i < points.size();i++)
        {
            dis.push_back({points[i][0]*points[i][0] + points[i][1]*points[i][1],i});
        }       

        sort(dis.begin(),dis.end());

        for(int i = 0;i<k;i++)
        {
            ans.push_back(points[dis[i][1]]);
        }

        return ans;
    }
};