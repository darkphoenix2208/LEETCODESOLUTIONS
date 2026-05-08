// Problem  : Remove Nth Node From End of List
// Difficulty: Medium
// Tags     : Linked List, Two Pointers
// URL      : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Solved on: 2026-04-09 00:08
// ──────────────────────────────────────────────────

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* a = head;
        while (a != nullptr) {
            count++;
            a = a->next;
        }

        int b = count - n;
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while (b--) {
            prev = temp;
            temp = temp->next;
        }

        if (prev != nullptr) {
            prev->next = temp->next;
        } else {
          
            head = head->next;
        }

        delete temp;
        return head;
    }
};


// Auto-commit update
