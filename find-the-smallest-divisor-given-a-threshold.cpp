// Problem  : Find the Smallest Divisor Given a Threshold
// Difficulty: Medium
// Tags     : Array, Binary Search
// URL      : https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
// Solved on: 2026-04-09 00:19
// ──────────────────────────────────────────────────

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
       int low=1,high=*max_element(nums.begin(), nums.end());
      int ans;
       int mid;
       while(low<=high){
         int count=0;
         mid=(low+high)/2;
        for (int i = 0; i < nums.size(); i++) {
        count += std::ceil((double)nums[i] / mid); 
    }
    if(count>threshold){
low=mid+1;
    }
    else{
        ans=mid;
        high=mid-1;
    }
  }
     return ans;
    }
};

// Auto-commit update
