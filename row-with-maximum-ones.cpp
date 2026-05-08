// Problem  : Row With Maximum Ones
// Difficulty: Easy
// Tags     : Array, Matrix
// URL      : https://leetcode.com/problems/row-with-maximum-ones/
// Solved on: 2026-04-09 00:19
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxCount = 0;
        int rowIndex = 0;

        for (int i = 0; i < mat.size(); ++i) {
            int ones = count(mat[i].begin(), mat[i].end(), 1);
            if (ones > maxCount) {
                maxCount = ones;
                rowIndex = i;
            }
        }
        return {rowIndex, maxCount};
    }
};


// Auto-commit update
