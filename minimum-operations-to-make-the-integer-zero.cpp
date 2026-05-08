// Problem  : Minimum Operations to Make the Integer Zero
// Difficulty: Medium
// Tags     : Bit Manipulation, Brainteaser, Enumeration
// URL      : https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/
// Solved on: 2026-04-09 00:13
// ──────────────────────────────────────────────────

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
       for (int i = 1; i <= 60; i++) {
    long long x = num1 - 1LL * i * num2;
    if (x < 0) break; 

    if (__builtin_popcountll(x) <= i && i <= x) {
        return i; 
    }
}
return -1; 

        
    }
};

// Auto-commit update
