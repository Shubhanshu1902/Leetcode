#include <bits/stdc++.h>
using namespace std;

/*
Question is to find distance of nearest 0 for each cell
*/

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size();
        if (m == 0)
            return mat;
        int n = mat[0].size();

        vector<vector<int>> res(m, vector<int>(n, INT_MAX-10000));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                    res[i][j] = 0;
                else
                {
                    if (i > 0)
                        res[i][j] = min(res[i - 1][j] + 1, res[i][j]);
                    if (j > 0)
                        res[i][j] = min(res[i][j - 1] + 1, res[i][j]);
                }
            }
        }

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (i < m - 1)
                    res[i][j] = min(res[i][j], res[i + 1][j] + 1);

                if (j < n - 1)
                    res[i][j] = min(res[i][j + 1] + 1, res[i][j]);
            }
        }

        return res;
    }
};