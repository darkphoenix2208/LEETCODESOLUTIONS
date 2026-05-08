// Problem  : Minimum Path Sum
// Difficulty: Medium
// Tags     : Array, Dynamic Programming, Matrix
// URL      : https://leetcode.com/problems/minimum-path-sum/
// Solved on: 2026-04-09 00:00
// ──────────────────────────────────────────────────

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
         int n = grid.size();
        int m = grid[0].size();
         vector<vector<int>> dp(n, vector<int>(m, 0));
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                        dp[i][j]=grid[i][j];
                }
                else{
                int up,down;
                if(i>0){
            up=dp[i-1][j]+grid[i][j];
                }
                else{
                    up=1e9;
                }
                if(j>0){
                    down=dp[i][j-1]+grid[i][j];
                }
                else{
                    down=1e9;
                }
                dp[i][j]=min(up,down);
            }
            }
         }
         return dp[n-1][m-1];
    }
};

// Auto-commit update
