// Problem  : Rotate Array
// Difficulty: Medium
// Tags     : Array, Math, Two Pointers
// URL      : https://leetcode.com/problems/rotate-array/
// Solved on: 2026-04-09 00:19
// ──────────────────────────────────────────────────

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  // handle k > n
        vector<int> arr;

        // Step 1: Add last k elements
        for(int i = n - k; i < n; i++) {
            arr.push_back(nums[i]);
        }

        // Step 2: Add first n - k elements
        for(int i = 0; i < n - k; i++) {
            arr.push_back(nums[i]);
        }

        // Step 3: Replace nums with arr
        nums = arr;
    }
};


// Auto-commit update
