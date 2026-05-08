// Problem  : Longest Common Subsequence
// Difficulty: Medium
// Tags     : String, Dynamic Programming
// URL      : https://leetcode.com/problems/longest-common-subsequence/
// Solved on: 2026-04-08 23:59
// ──────────────────────────────────────────────────

class Solution {
public:
    int f(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]){
            dp[i][j]=1+f(s1,s2,i-1,j-1,dp);
        }
        else{
            dp[i][j]=max(f(s1,s2,i,j-1,dp),f(s1,s2,i-1,j,dp));
        }

        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int i=text1.length();
        int j=text2.length();
        
        vector<vector<int>>dp(i,vector<int>(j,-1));
        return f(text1,text2,i-1,j-1,dp);
    }
};

// Auto-commit update
