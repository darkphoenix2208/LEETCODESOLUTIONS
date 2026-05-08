// Problem  : Best Time to Buy and Sell Stock with Transaction Fee
// Difficulty: Medium
// Tags     : Array, Dynamic Programming, Greedy
// URL      : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
// Solved on: 2026-04-08 23:55
// ──────────────────────────────────────────────────

class Solution {
public:
int f(int i, int n,
      vector<vector<int>>& dp,
      vector<int>& p, int b, int fee)
{
    if (i == n) return 0;

    if (dp[i][b] != -1)
        return dp[i][b];

    int ans;
    if (b) {
        ans = max(
            p[i] - fee + f(i+1, n, dp, p, 0, fee), 
            f(i+1, n, dp, p, 1, fee)              
        );
    } else {
        ans = max(
            f(i+1, n, dp, p, 0, fee),         
            f(i+1, n, dp, p, 1, fee) - p[i]       
        );
    }

    return dp[i][b] = ans;
}

int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return f(0, n, dp, prices, 0, fee);
}
};


// Auto-commit update
