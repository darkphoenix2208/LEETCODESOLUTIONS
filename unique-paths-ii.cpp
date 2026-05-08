// Problem  : Unique Paths II
// Difficulty: Medium
// Tags     : Array, Dynamic Programming, Matrix
// URL      : https://leetcode.com/problems/unique-paths-ii/
// Solved on: 2026-04-09 00:00
// ──────────────────────────────────────────────────

class Solution {
public:
    int func(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& o) {
      
        if (i < 0 || j < 0) return 0;

        if (o[i][j] == 1) return 0;

        if (i == 0 && j == 0) return 1;

        if (dp[i][j] != -1) return dp[i][j];

        int up = func(i - 1, j, dp, o);
        int left = func(i, j - 1, dp, o);

        return dp[i][j] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int n = o.size();        
        int m = o[0].size();     

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return func(n - 1, m - 1, dp, o);
    }
};


// Auto-commit update
