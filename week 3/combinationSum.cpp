#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> res;

    void findSol(int i, vector<int> &candidates, int target, vector<int> &cur)
    {
        if (target == 0)
        {
            res.push_back(cur);
            return;
        }

        if (target < 0)
            return;

        if (i == candidates.size())
            return;

        findSol(i + 1, candidates, target, cur);

        cur.push_back(candidates[i]);
        findSol(i, candidates, target - candidates[i], cur);
        cur.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> cur;
        findSol(0,candidates,target,cur);
        return res;
    }
};