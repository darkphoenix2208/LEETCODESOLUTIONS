// Problem  : Longest Subarray of 1's After Deleting One Element
// Difficulty: Medium
// Tags     : Array, Dynamic Programming, Sliding Window
// URL      : https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
// Solved on: 2026-04-09 00:15
// ──────────────────────────────────────────────────



class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0, zeros = 0, maxLen = 0;

        for (int right = 0; right < n; right++) {
            if (nums[right] == 0) zeros++;

            while (zeros > 1) {
                if (nums[left] == 0) zeros--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen - 1;
    }
};


// Auto-commit update
