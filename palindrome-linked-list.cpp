// Problem  : Palindrome Linked List
// Difficulty: Easy
// Tags     : Linked List, Two Pointers, Stack, Recursion
// URL      : https://leetcode.com/problems/palindrome-linked-list/
// Solved on: 2026-04-09 00:07
// ──────────────────────────────────────────────────

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> arr;

        while (head != nullptr) {
            arr.push_back(head->val);
            head = head->next;
        }

        int left = 0;
        int right = arr.size() - 1;

        while (left < right) {
            if (arr[left] != arr[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;        
    }
};

// Auto-commit update
