// Problem  : Next Greater Numerically Balanced Number
// Difficulty: Medium
// Tags     : Hash Table, Math, Backtracking, Counting, Enumeration
// URL      : https://leetcode.com/problems/next-greater-numerically-balanced-number/
// Solved on: 2026-04-09 00:06
// ──────────────────────────────────────────────────

class Solution {
public:
    bool isBalance(int x) {
        vector<int> count(10);
        while (x > 0) {
            count[x % 10]++;
            x /= 10;
        }
        for (int d = 0; d < 10; ++d) {
            if (count[d] > 0 && count[d] != d) {
                return false;
            }
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        for (int i = n + 1; i <= 1224444; ++i) {
            if (isBalance(i)) {
                return i;
            }
        }
        return -1;
    }
};

// Auto-commit update
