// Problem  : Minimum One Bit Operations to Make Integers Zero
// Difficulty: Hard
// Tags     : Math, Dynamic Programming, Bit Manipulation, Recursion, Memoization
// URL      : https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/
// Solved on: 2026-04-09 00:05
// ──────────────────────────────────────────────────

class Solution {
public:
    int minimumOneBitOperations(int n) {
        int res = 0;
        while (n) {
            res ^= n;
            n >>= 1;
        }
        return res;
    }
};

// Auto-commit update
