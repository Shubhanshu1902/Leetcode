#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool checkCycle(int node,vector<vector<int>> &adj,vector<int> &vis,vector<int> &dfs){
        vis[node] = 1;
        dfs[node] = 1;
        for(auto i:adj[node]){
            if(!vis[i]){
                if(checkCycle(i,adj,vis,dfs)) return true;
            }
            else if(dfs[i]) return true;
        }

        dfs[node] = 0;
        return false;
    }

    bool isCycle(int N,vector<vector<int>> &adj){
        vector<int> visited(N);
        vector<int> dfs_visited(N);

        for(int i = 0; i < N;i++)
        {
            if(!visited[i]){
                if(checkCycle(i,adj,visited,dfs_visited)) return true;
            }
        }

        return false;

    }

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj_list(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            adj_list[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        // Detect cycle
        vector<int> visited(numCourses);
        vector<int> dfs_visited(numCourses);

        bool ans = isCycle(numCourses,adj_list);
        return !ans;
    }
};