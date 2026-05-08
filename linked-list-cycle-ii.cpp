// Problem  : Linked List Cycle II
// Difficulty: Medium
// Tags     : Hash Table, Linked List, Two Pointers
// URL      : https://leetcode.com/problems/linked-list-cycle-ii/
// Solved on: 2026-04-09 00:08
// ──────────────────────────────────────────────────

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        unordered_set<ListNode*> seen;
        ListNode* temp = head;

        while (temp != nullptr) {
            if (seen.find(temp) != seen.end()) {
                return temp;
            }
            seen.insert(temp);
            temp = temp->next;
        }

        return nullptr; 
    }
};


// Auto-commit update
