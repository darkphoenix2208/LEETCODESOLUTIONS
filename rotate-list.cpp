// Problem  : Rotate List
// Difficulty: Medium
// Tags     : Linked List, Two Pointers
// URL      : https://leetcode.com/problems/rotate-list/
// Solved on: 2026-05-08 21:46
// ──────────────────────────────────────────────────

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
class Solution{
public:
    ListNode* rotateRight(ListNode* head,int k){
        if(!head||!head->next||k==0) return head; 

        int len=1;
        ListNode* tail=head;
        while(tail->next){ tail=tail->next; len++; } 

        k%=len;
        if(k==0) return head; 

        tail->next=head;

        int steps=len-k;
        ListNode* newtail=head;
        for(int i=1;i<steps;i++) newtail=newtail->next; 

        ListNode* newhead=newtail->next; 
        newtail->next=NULL;

        return newhead;
    }
};

// Auto-commit update
