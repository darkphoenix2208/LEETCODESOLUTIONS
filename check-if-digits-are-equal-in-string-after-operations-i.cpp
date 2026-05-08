// Problem  : Check If Digits Are Equal in String After Operations I
// Difficulty: Easy
// Tags     : Math, String, Simulation, Combinatorics, Number Theory
// URL      : https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i/
// Solved on: 2026-04-09 00:06
// ──────────────────────────────────────────────────

class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.length();
        for (int i = 1; i <= n - 2; i++) {
            for (int j = 0; j <= n - 1 - i; j++) {
                s[j] = ((s[j] - '0') + (s[j + 1] - '0')) % 10 + '0';
            }
        }
        return s[0] == s[1];
    }
};

// Auto-commit update
