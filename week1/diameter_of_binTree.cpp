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

class Solution{
private: 
    int diameter = 0;
    int getTreeLength(TreeNode* root){
        if(!root) return 0;
        int l = getTreeLength(root->left),r = getTreeLength(root->right);
        diameter = max(diameter,l+r);
        return max(l,r) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        getTreeLength(root);
        return diameter;
    }
};