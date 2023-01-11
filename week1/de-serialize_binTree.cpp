#include <bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        queue<TreeNode *> cur;
        string res = "";

        if(!root) return res;

        cur.push(root);
        
        while (!cur.empty())
        {
            TreeNode* q = cur.front();
            cur.pop();

            if(q) res += to_string(q->val)+',';
            else res+="null,";

            if(q){
                cur.push(q->left);
                cur.push(q->right);
            }   
        }

        return res;  
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if(!data.size()) return NULL;

        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));