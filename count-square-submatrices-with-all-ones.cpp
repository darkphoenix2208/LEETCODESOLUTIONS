// Problem  : Count Square Submatrices with All Ones
// Difficulty: Medium
// Tags     : Array, Dynamic Programming, Matrix
// URL      : https://leetcode.com/problems/count-square-submatrices-with-all-ones/
// Solved on: 2026-04-09 00:15
// ──────────────────────────────────────────────────

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        int count = 0;

        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if (matrix[i][j] == 1) {
                    if (i == 0 || j == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                    
                    count += dp[i][j];
                }
            }
        }

        return count;
    }
};


// Auto-commit update
