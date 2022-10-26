#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void sol(vector<vector<int>> &image, int sr, int sc, int rows, int col, int color, int src)
    {
        if (sr < 0 || sr >= rows || sc < 0 || sc >= col || image[sr][sc] != src)
            return;
        image[sr][sc] = color;
        sol(image, sr + 1, sc, rows, col, color, src);
        sol(image, sr - 1, sc, rows, col, color, src);
        sol(image, sr, sc + 1, rows, col, color, src);
        sol(image, sr, sc - 1, rows, col, color, src);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        if (color == image[sr][sc])
            return image;
        int val = image[sr][sc];
        int row = image.size();
        int col = image[0].size();
        sol(image, sr, sc, row, col, color, val);
        return image;
    }
};