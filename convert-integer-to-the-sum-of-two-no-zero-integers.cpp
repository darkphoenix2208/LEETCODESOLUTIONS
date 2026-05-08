// Problem  : Convert Integer to the Sum of Two No-Zero Integers
// Difficulty: Easy
// Tags     : Math
// URL      : https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/
// Solved on: 2026-04-09 00:13
// ──────────────────────────────────────────────────

class Solution {
public:
    
    bool hasZero(int n) {
        string s = to_string(n);
        for (char c : s) {
            if (c == '0') return true;
        }
        return false;
    }

    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i++) {
            if (!hasZero(i) && !hasZero(n - i)) {
                return {i, n - i};
            }
        }
        return {};
    }
};


// Auto-commit update
