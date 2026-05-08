// Problem  : Remove Duplicates from Sorted List
// Difficulty: Easy
// Tags     : Linked List
// URL      : https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// Solved on: 2026-04-09 00:08
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;

        ListNode* temp = head;
        while (temp) {
            if (temp->next && temp->val == temp->next->val) {
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }

        return head;
    }
};

// Auto-commit update
