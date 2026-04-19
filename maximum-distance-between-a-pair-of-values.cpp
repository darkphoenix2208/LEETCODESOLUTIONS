// Problem  : Maximum Distance Between a Pair of Values
// Difficulty: Medium
// Tags     : Array, Two Pointers, Binary Search
// URL      : https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/
// Solved on: 2026-05-08 21:48
// ──────────────────────────────────────────────────

class Solution {
public:
    int maxDistance(vector<int>& A, vector<int>& B) {
        int i, j;

        for (i = 0, j = 0; i < A.size() && j < B.size(); j++)
            i += A[i] > B[j];

        return max(0, j - i - 1);
    }
};

// Auto-commit update
