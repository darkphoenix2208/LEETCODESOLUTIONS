// Problem  : House Robber V
// Difficulty: Medium
// Tags     : Array, Dynamic Programming
// URL      : https://leetcode.com/problems/house-robber-v/
// Solved on: 2026-05-08 21:53
// ──────────────────────────────────────────────────

class Solution {
public:
    long long f(vector<int>& colors,vector<int>& nums,int t,vector<long long>&dp){
        if(t<0) return 0;
        if(dp[t]!=-1) return dp[t];
        
        if(t==0) return nums[0];
        long long  s=f(colors,nums,t-1,dp);
         long long ta;
        if(colors[t]==colors[t-1]){
            ta=nums[t]+f(colors,nums,t-2,dp);
        }
        else{
            ta=nums[t]+f(colors,nums,t-1,dp);
        }
        return dp[t]=max(ta,s);
    }
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n=nums.size();
        vector<long long >dp(n,-1);
        return f(colors,nums,n-1,dp);

        
    }
};

// Auto-commit update
