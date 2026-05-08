// Problem  : Delete Nodes From Linked List Present in Array
// Difficulty: Medium
// Tags     : Array, Hash Table, Linked List
// URL      : https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/
// Solved on: 2026-04-09 00:05
// ──────────────────────────────────────────────────

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> toDelete(nums.begin(), nums.end());
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr != nullptr) {
            if (toDelete.count(curr->val)) {
                prev->next = curr->next;
                
            } else {
                prev = curr;
            }
            curr = prev->next;
        }

        return dummy->next; 
    }
};


// Auto-commit update
