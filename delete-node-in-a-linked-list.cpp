// Problem  : Delete Node in a Linked List
// Difficulty: Medium
// Tags     : Linked List
// URL      : https://leetcode.com/problems/delete-node-in-a-linked-list/
// Solved on: 2026-04-09 00:08
// ──────────────────────────────────────────────────

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node->next;
        *node = *node->next;
        delete temp;
    }
};

// Auto-commit update
