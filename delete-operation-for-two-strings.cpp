// Problem  : Delete Operation for Two Strings
// Difficulty: Medium
// Tags     : String, Dynamic Programming
// URL      : https://leetcode.com/problems/delete-operation-for-two-strings/
// Solved on: 2026-04-08 23:58
// ──────────────────────────────────────────────────

class Solution {
public:
int f(string &s,string &t,int i,int j,vector<vector<int>>&dp){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1)return dp[i][j];
     
     if(s[i]==t[j]) dp[i][j]=1+f(s,t,i-1,j-1,dp);
    else{
        dp[i][j]=max(f(s,t,i-1,j,dp),f(s,t,i,j-1,dp));
    }

     return dp[i][j];
}
    int minDistance(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return s.length()+t.length()-2*f(s,t,s.length()-1,t.length()-1,dp);
    }
};

// Auto-commit update
