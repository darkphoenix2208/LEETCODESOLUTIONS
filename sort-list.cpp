// Problem  : Sort List
// Difficulty: Medium
// Tags     : Linked List, Two Pointers, Divide and Conquer, Sorting, Merge Sort
// URL      : https://leetcode.com/problems/sort-list/
// Solved on: 2026-04-09 00:07
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
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) return nullptr;

        vector<int> v;


        ListNode* current = head;
        while (current != nullptr) {
            v.push_back(current->val);
            current = current->next;
        }

    
        sort(v.begin(), v.end());


        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        for (int val : v) {
            tail->next = new ListNode(val);
            tail = tail->next;
        }

        return dummy->next;
    }
};


// Auto-commit update
