// Problem  : Merge Two Sorted Lists
// Difficulty: Easy
// Tags     : Linked List, Recursion
// URL      : https://leetcode.com/problems/merge-two-sorted-lists/
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> v;


        ListNode* current = list1;
        while (current != nullptr) {
            v.push_back(current->val);
            current = current->next;
        }


        current = list2;
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
