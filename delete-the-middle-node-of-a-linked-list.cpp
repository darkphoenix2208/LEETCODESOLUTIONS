// Problem  : Delete the Middle Node of a Linked List
// Difficulty: Medium
// Tags     : Linked List, Two Pointers
// URL      : https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
// Solved on: 2026-04-09 00:08
// ──────────────────────────────────────────────────

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return nullptr;

        int count = 0;
        ListNode* a = head;
        while (a != nullptr) {
            count++;
            a = a->next;
        }

        int b = count / 2;
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while (b--) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
        delete temp; 
        return head;
    }
};


// Auto-commit update
