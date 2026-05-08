// Problem  : Minimum Difference Between Highest and Lowest of K Scores
// Difficulty: Easy
// Tags     : Array, Sliding Window, Sorting
// URL      : https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/
// Solved on: 2026-04-08 23:56
// ──────────────────────────────────────────────────

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<n-k+1;i++){
            ans=min(ans,nums[i+k-1]-nums[i]);
        }
        return ans;
    }
};

// Auto-commit update
