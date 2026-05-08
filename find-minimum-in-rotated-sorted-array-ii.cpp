// Problem  : Find Minimum in Rotated Sorted Array II
// Difficulty: Hard
// Tags     : Array, Binary Search
// URL      : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
// Solved on: 2026-04-09 00:17
// ──────────────────────────────────────────────────

class Solution {
public:
    int findMin(vector<int>& nums) {
   std::sort(nums.begin(), nums.end());
      return nums[0];
    }
};

// Auto-commit update
