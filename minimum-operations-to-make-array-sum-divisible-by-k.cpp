// Problem  : Minimum Operations to Make Array Sum Divisible by K
// Difficulty: Easy
// Tags     : Array, Math
// URL      : https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/
// Solved on: 2026-04-09 00:03
// ──────────────────────────────────────────────────

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        return accumulate(nums.begin(), nums.end(), 0) % k;
    }
};

// Auto-commit update
