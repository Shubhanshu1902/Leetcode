#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        vector<ListNode*> vals;
        ListNode* curr = head;
        while (curr)
        {
            vals.push_back(curr);
            curr = curr->next;
        }   

        int mid = vals.size()/2;
        return vals[mid];
    }
};