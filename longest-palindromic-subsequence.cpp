// Problem  : Longest Palindromic Subsequence
// Difficulty: Medium
// Tags     : String, Dynamic Programming
// URL      : https://leetcode.com/problems/longest-palindromic-subsequence/
// Solved on: 2026-04-08 23:59
// ──────────────────────────────────────────────────

class Solution {
public:
int f(string &s,string &t,int i,int j,vector<vector<int>>& dp){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    if(s[i]==t[j]){
        dp[i][j]=f(s,t,i-1,j-1,dp)+1;
    }else{
        dp[i][j]=max(f(s,t,i,j-1,dp),f(s,t,i-1,j,dp));
    }
    return dp[i][j];
}
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        string t=s;
        reverse(t.begin(),t.end());
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(s,t,n-1,n-1,dp);
    }
};

// Auto-commit update
