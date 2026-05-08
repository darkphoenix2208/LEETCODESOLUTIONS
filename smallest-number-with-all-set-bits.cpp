// Problem  : Smallest Number With All Set Bits
// Difficulty: Easy
// Tags     : Math, Bit Manipulation
// URL      : https://leetcode.com/problems/smallest-number-with-all-set-bits/
// Solved on: 2026-04-09 00:06
// ──────────────────────────────────────────────────

class Solution {
public:
    int smallestNumber(int n) {
        vector<int> a = {1,3,7,15,31,63,127,255,511,1023};
        for (int x : a) if (x >= n) return x;
        return -1;
    }
};

// Auto-commit update
