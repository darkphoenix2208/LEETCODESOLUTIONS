// Problem  : Count Odd Numbers in an Interval Range
// Difficulty: Easy
// Tags     : Math
// URL      : https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/
// Solved on: 2026-04-09 00:03
// ──────────────────────────────────────────────────

class Solution {
public:
    int countOdds(int low, int high) {
        int total = high - low + 1;
        if (low % 2 != 0 && high % 2 != 0) return total / 2 + 1;
        return total / 2;
    }
};

// Auto-commit update
