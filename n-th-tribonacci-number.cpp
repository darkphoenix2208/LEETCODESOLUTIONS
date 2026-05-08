// Problem  : N-th Tribonacci Number
// Difficulty: Easy
// Tags     : Math, Dynamic Programming, Memoization
// URL      : https://leetcode.com/problems/n-th-tribonacci-number/
// Solved on: 2026-04-08 23:59
// ──────────────────────────────────────────────────

class Solution {
public:
int f(int n,vector<int>&dp){
if(dp[n]!=-1) return dp[n];
if(n==0)return 0;
if(n==1) return 1;
if(n==2)return 1;
dp[n]=f(n-1,dp)+f(n-2,dp)+f(n-3,dp);
return dp[n];
}
    int tribonacci(int n) {
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }
};

// Auto-commit update
