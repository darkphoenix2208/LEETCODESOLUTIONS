// Problem  : Swap Nodes in Pairs
// Difficulty: Medium
// Tags     : Linked List, Recursion
// URL      : https://leetcode.com/problems/swap-nodes-in-pairs/
// Solved on: 2026-04-09 00:08
// ──────────────────────────────────────────────────

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* a = head;
        ListNode* b = head->next;
        ListNode* newHead = b; 

        while (a != nullptr && a->next != nullptr) {
            b = a->next;
            ListNode* temp = b->next;
            b->next = a;

            if (temp == nullptr || temp->next == nullptr) {
                a->next = temp;
                break;
            } else {
                a->next = temp->next; 
            }

            a = temp;
        }

        return newHead;
    }
};


// Auto-commit update
