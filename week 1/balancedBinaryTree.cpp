#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
    bool ans;
    int height(TreeNode *root)
    {
        if (!root)
            return 0;
        if (!ans)
            return 0;
        int leftTree = height(root->left);
        int rightTree = height(root->right);
        if (abs(leftTree - rightTree) > 1)
            ans = false;
        return 1 + max(height(root->left), height(root->right));
    }

public:
    bool isBalanced(TreeNode *root)
    {
        ans = true;
        height(root);
        return ans;
    }
};