// Problem  : Minimum Insertion Steps to Make a String Palindrome
// Difficulty: Hard
// Tags     : String, Dynamic Programming
// URL      : https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
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
    int minInsertions(string s) {
        int n=s.length();
        string  t=s;
        reverse(t.begin(),t.end());
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return n-f(s,t,n-1,n-1,dp);
    }
};

// Auto-commit update
