// Problem  : Count Partitions with Even Sum Difference
// Difficulty: Easy
// Tags     : Array, Math, Prefix Sum
// URL      : https://leetcode.com/problems/count-partitions-with-even-sum-difference/
// Solved on: 2026-04-09 00:03
// ──────────────────────────────────────────────────

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        return (reduce(nums.begin(), nums.end(), 0)&1)?0:nums.size()-1;
    }
};

// Auto-commit update
