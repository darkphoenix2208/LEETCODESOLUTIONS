// Problem  : Count Operations to Obtain Zero
// Difficulty: Easy
// Tags     : Math, Simulation
// URL      : https://leetcode.com/problems/count-operations-to-obtain-zero/
// Solved on: 2026-04-09 00:04
// ──────────────────────────────────────────────────

class Solution {
public:
    int countOperations(int num1, int num2) {
        long long a = num1, b = num2;
        int ops = 0;
        while (a > 0 && b > 0) {
            if (a < b) std::swap(a, b);
            ops += a / b;
            a %= b;
        }
        return ops;
    }
};

// Auto-commit update
