// Problem  : Minimize Maximum Pair Sum in Array
// Difficulty: Medium
// Tags     : Array, Two Pointers, Greedy, Sorting
// URL      : https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/
// Solved on: 2026-04-08 23:56
// ──────────────────────────────────────────────────

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=INT_MIN;
        int n=nums.size();
        int l=0,r=n-1;
        while(l<=r){
            ans=max(ans,nums[l]+nums[r]);
            l++;
            r--;
        }
        return ans;
    }
};

// Auto-commit update
