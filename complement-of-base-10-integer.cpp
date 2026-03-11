// Problem  : Complement of Base 10 Integer
// Difficulty: Easy
// Tags     : Bit Manipulation
// URL      : https://leetcode.com/problems/complement-of-base-10-integer/
// Solved on: 2026-05-08 21:51
// ──────────────────────────────────────────────────

class Solution {
public:
    int bitwiseComplement(int n) {

        if(n==0) return 1;

        int bits = log2(n) + 1;
        int mask = (1<<bits) - 1;

        return n ^ mask;
    }
};

// Auto-commit update
