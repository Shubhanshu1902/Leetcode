#include <bits/stdc++.h>
using namespace std;

/*
In this problem, we solved the problem by two approach
1) Recursive
    
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode* sol;
        ListNode* temp1,*temp2,*temp;

        if(list1 == NULL) return list2;
        else if(list2 == NULL) return list1;
        else if(list1->val < list2->val){
            list1->next = mergeTwoLists(list1->next,list2);
            return list1;
        }
        else{
            list2->next = mergeTwoLists(list1,list2->next);
            return list2;
        }
    }
};

// Iterative
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode* sol;
        ListNode* cur;
        
        if(!list1) return list2;
        else if(!list2) return list1;

        sol = list1; 
        if(list1->val < list2->val){
            list1 = list1->next;
        }
        else{
            sol = list2;
            list2 = list2->next;
        }

        cur = sol;

        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                cur->next = list1;
                list1 = list1->next;
            }

            else
            {
                cur->next = list2;
                list2 = list2->next;
            }

            cur = cur->next;
        }

        if(list1){
            cur->next = list1;
        }

        else if(list2){
            cur->next = list2;
        }

        return sol;
    }
};