// Problem  : Max Consecutive Ones III
// Difficulty: Medium
// Tags     : Array, Binary Search, Sliding Window, Prefix Sum
// URL      : https://leetcode.com/problems/max-consecutive-ones-iii/
// Solved on: 2026-04-09 00:07
// ──────────────────────────────────────────────────

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        
        for (int r = 0; r < nums.size(); ++r) {
            if (nums[r] == 0) {
                k--;  
            }

            if (k < 0) {
                if (nums[l] == 0) {
                    k++; 
                }
                l++;
            }
        }
        
        return nums.size() - l;
    }
};


// Auto-commit update
