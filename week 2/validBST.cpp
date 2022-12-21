#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
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
private:
    bool validate(TreeNode *root,TreeNode *min,TreeNode *max){
        if(!root) return true;
        if((min && root->val <= min->val) || (max && root->val >= max->val)) return false;
        return validate(root->right,root,max) && validate(root->left,min,root);
    }

public:
    bool isValidBST(TreeNode *root)
    {
        bool res = true;
        return validate(root,nullptr,nullptr);
    }
};