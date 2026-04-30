// Problem  : Maximum Path Score in a Grid
// Difficulty: Medium
// Tags     : Array, Dynamic Programming, Matrix
// URL      : https://leetcode.com/problems/maximum-path-score-in-a-grid/
// Solved on: 2026-05-08 21:47
// ──────────────────────────────────────────────────

class Solution {
public:
    int maxPathScore(vector<vector<int>>& g, int k) {
        int n = g.size(), m = g[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k+1, -1e9)));

        dp[0][0][0] = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int c = 0; c <= k; c++){
                    if(dp[i][j][c] < 0) continue;

                    
                    if(i + 1 < n){
                        int nc = c + (g[i+1][j] != 0);
                        int ns = dp[i][j][c] + g[i+1][j];

                        if(nc <= k){
                            dp[i+1][j][nc] = max(dp[i+1][j][nc], ns);
                        }
                    }

        
                    if(j + 1 < m){
                        int nc = c + (g[i][j+1] != 0);
                        int ns = dp[i][j][c] + g[i][j+1];

                        if(nc <= k){
                            dp[i][j+1][nc] = max(dp[i][j+1][nc], ns);
                        }
                    }
                }
            }
        }

        int ans = -1;
        for(int c = 0; c <= k; c++){
            ans = max(ans, dp[n-1][m-1][c]);
        }

        return ans < 0 ? -1 : ans;
    }
};

// Auto-commit update
