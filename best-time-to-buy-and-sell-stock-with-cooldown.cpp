// Problem  : Best Time to Buy and Sell Stock with Cooldown
// Difficulty: Medium
// Tags     : Array, Dynamic Programming
// URL      : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
// Solved on: 2026-04-08 23:55
// ──────────────────────────────────────────────────

class Solution {
public:
int f(int i,int n,vector<vector<vector<int>>>& dp,
      vector<int>& p,int b,int t){

    if(i==n) return 0;

    if(dp[i][b][t] != -1)
        return dp[i][b][t];

    int ans=0;
    if(b){
        if(t==0){
        ans = max(
            p[i] + f(i+1,n,dp,p,0,1), 
            f(i+1,n,dp,p,1,0)         
        );
        }
        else{
           ans= f(i+1,n,dp,p,1,0) ;
        }
    }
    else{
        if(t==0){
        ans = max(
            f(i+1,n,dp,p,0,0),      
            f(i+1,n,dp,p,1,0) - p[i]   
        );
    }
    else{
        ans=f(i+1,n,dp,p,0,0);
    }
    }

    return dp[i][b][t] = ans;
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(2, vector<int>(3, -1))
    );
    return f(0,n,dp,prices,0,0);
}
};


// Auto-commit update
