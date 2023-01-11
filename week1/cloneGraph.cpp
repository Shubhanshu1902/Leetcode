#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return node;
        }

        unordered_map<Node*,Node*> copy;
        Node* node_clone = new Node(node->val,{});
        copy[node] = node_clone;

        queue<Node *> bfs;
        bfs.push(node);

        while (!bfs.empty())
        {
            for (auto it: bfs.front()->neighbors)
            {
                if(copy.find(it) == copy.end()){
                    copy[it] = new Node(it->val,{});
                    bfs.push(it);
                }

                copy[bfs.front()]->neighbors.push_back(copy[it]);
            }

            bfs.pop();
        }
        
        return copy[node];
    }
};