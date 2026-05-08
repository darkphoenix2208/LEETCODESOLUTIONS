// Problem  : Best Time to Buy and Sell Stock IV
// Difficulty: Hard
// Tags     : Array, Dynamic Programming
// URL      : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
// Solved on: 2026-04-08 23:55
// ──────────────────────────────────────────────────

class Solution {
public:
int f(int i,int n,vector<vector<vector<int>>>& dp,
      vector<int>& p,int b,int t,int k){

    if(i==n || t==k) return 0;

    if(dp[i][b][t] != -1)
        return dp[i][b][t];

    int ans=0;
    if(b){
        ans = max(
            p[i] + f(i+1,n,dp,p,0,t+1,k), 
            f(i+1,n,dp,p,1,t,k)         
        );
    }
    else{
        ans = max(
            f(i+1,n,dp,p,0,t,k),      
            f(i+1,n,dp,p,1,t,k) - p[i]   
        );
    }

    return dp[i][b][t] = ans;
}

int maxProfit(int k,vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(2, vector<int>(k+1, -1))
    );
    return f(0,n,dp,prices,0,0,k);
}
};


// Auto-commit update
