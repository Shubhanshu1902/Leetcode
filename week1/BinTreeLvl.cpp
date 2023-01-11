#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
            return vector<vector<int>>();

        queue<pair<TreeNode *, int>> nodes;
        nodes.push({root, 0});
        vector<vector<int>> res;
        int level = 0;
        vector<int> tmp;

        while (!nodes.empty())
        {
            if (nodes.front().first->left)
            {
                nodes.push({nodes.front().first->left, nodes.front().second + 1});
            }

            if (nodes.front().first->right)
            {
                nodes.push({nodes.front().first->right, nodes.front().second + 1});
            }

            if (nodes.front().second == level)
            {
                tmp.push_back(nodes.front().first->val);
                nodes.pop();
            }

            else if (nodes.front().second >= level + 1)
            {
                res.push_back(tmp);
                level++;
                tmp.clear();
                tmp.push_back(nodes.front().first->val);
                nodes.pop();
            }
        }

        res.push_back(tmp);
        return res;
    }
};