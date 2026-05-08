// Problem  : Merge k Sorted Lists
// Difficulty: Hard
// Tags     : Linked List, Divide and Conquer, Heap (Priority Queue), Merge Sort
// URL      : https://leetcode.com/problems/merge-k-sorted-lists/
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;

        for (int i = 0; i < lists.size(); i++) {
            ListNode* current = lists[i];
            while (current != nullptr) {
                v.push_back(current->val);
                current = current->next;
            }
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
