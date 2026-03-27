// Problem  : Matrix Similarity After Cyclic Shifts
// Difficulty: Easy
// Tags     : Array, Math, Matrix, Simulation
// URL      : https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/
// Solved on: 2026-05-08 21:50
// ──────────────────────────────────────────────────

class Solution {
public:
    bool areSimilar(vector<vector<int>>& a, int k) {
        int m = a.size(), n = a[0].size();

        k %= n;

        for (int i = 0; i < m; i++) {
            vector<int> b = a[i];

            if (i % 2 == 0) {
                rotate(b.begin(), b.begin() + k, b.end());
            } else {
                rotate(b.begin(), b.end() - k, b.end());
            }

            if (b != a[i]) return false;
        }

        return true;
    }
};

// Auto-commit update
