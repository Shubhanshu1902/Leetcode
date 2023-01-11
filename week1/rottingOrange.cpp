#include <bits/stdc++.h>
using namespace std;

// We have a graph
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> all2s;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                    all2s.push({0, i * m + j});
            }
        }

        int step = 0;
        // 1,0
        // 0,1
        // -1,0
        // 0,-1
        vector<vector<int>> vis(grid);
        while (!all2s.empty())
        {
            int val = all2s.front().second;
            int i = val/m;
            int j = val%m;
            if (j < m - 1 && grid[i][j + 1] == 1 && vis[i][j + 1] != 2)
            {
                vis[i][j + 1] = 2;
                all2s.push({all2s.front().first + 1, i * m + (j+1)});
            }

            if (j > 0 && grid[i][j - 1] == 1 && vis[i][j - 1] != 2)
            {
                vis[i][j - 1] = 2;
                all2s.push({all2s.front().first + 1, i * m + (j-1)});
            }

            if (i < n - 1 && grid[i + 1][j] == 1 && vis[i + 1][j] != 2)
            {
                vis[i + 1][j] = 2;
                all2s.push({all2s.front().first + 1, (i+1) * m + j});
            }

            if (i > 0 && grid[i - 1][j] == 1 && vis[i - 1][j] != 2)
            {
                vis[i - 1][j] = 2;
                all2s.push({all2s.front().first + 1, (i-1) * m + j});
            }
            step = all2s.front().first;
            all2s.pop();
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] == 1)
                    return -1;
            }
        }

        return step;
    }
};