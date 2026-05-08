// Problem  : Count Negative Numbers in a Sorted Matrix
// Difficulty: Easy
// Tags     : Array, Binary Search, Matrix
// URL      : https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
// Solved on: 2026-04-09 00:01
// ──────────────────────────────────────────────────

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int i = m -1;
        int j = 0; 

        int res = 0;

        while (i >= 0 && j < n) {
            if (grid[i][j] < 0) {
                res += n - j;
                i--;
            } else
                j++;
        }

        return res;
    }
};


// Auto-commit update
