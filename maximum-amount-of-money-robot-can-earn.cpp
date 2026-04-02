// Problem  : Maximum Amount of Money Robot Can Earn
// Difficulty: Medium
// Tags     : Array, Dynamic Programming, Matrix
// URL      : https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/
// Solved on: 2026-05-08 21:49
// ──────────────────────────────────────────────────

class Solution {
public:
    int maximumAmount(vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size();

        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(3, -1e18)));

        if (a[0][0] >= 0) {
            dp[0][0][0] = a[0][0];
        } else {
            dp[0][0][0] = a[0][0];
            dp[0][0][1] = 0;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                for (int k = 0; k < 3; k++) {
                    long long x = -1e18;

                    if (i > 0) x = max(x, dp[i - 1][j][k]);
                    if (j > 0) x = max(x, dp[i][j - 1][k]);

                    if (x == -1e18) continue;

                    if (a[i][j] >= 0) {
                        dp[i][j][k] = max(dp[i][j][k], x + a[i][j]);
                    } else {
                        dp[i][j][k] = max(dp[i][j][k], x + a[i][j]);

                        if (k < 2) {
                            dp[i][j][k + 1] = max(dp[i][j][k + 1], x);
                        }
                    }
                }
            }
        }

        return max({dp[m - 1][n - 1][0], dp[m - 1][n - 1][1], dp[m - 1][n - 1][2]});
    }
};

// Auto-commit update
