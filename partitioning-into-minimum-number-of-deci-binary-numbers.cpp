// Problem  : Partitioning Into Minimum Number Of Deci-Binary Numbers
// Difficulty: Medium
// Tags     : String, Greedy
// URL      : https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
// Solved on: 2026-05-08 21:51
// ──────────────────────────────────────────────────

class Solution {
public:
    int minPartitions(string n) {
        int mx = 0;
        for(char c : n)
            mx = max(mx, c - '0');
        return mx;
    }
};

// Auto-commit update
