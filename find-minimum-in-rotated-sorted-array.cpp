// Problem  : Find Minimum in Rotated Sorted Array
// Difficulty: Medium
// Tags     : Array, Binary Search
// URL      : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Solved on: 2026-04-09 00:19
// ──────────────────────────────────────────────────

class Solution {
public:
    int findMin(vector<int>& nums) {
         auto min_it = std::min_element(nums.begin(), nums.end());

    int min_value = *min_it;
    return min_value;
    }
};

// Auto-commit update
