// Problem  : N-Repeated Element in Size 2N Array
// Difficulty: Easy
// Tags     : Array, Hash Table
// URL      : https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
// Solved on: 2026-04-09 00:00
// ──────────────────────────────────────────────────

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        
        vector<int>a(1e4,0);
        for(int i=0;i<nums.size();i++){
            a[nums[i]]++;
        }
        for(int i=0;i<=1e4;i++){
            if(a[i]==(nums.size()/2)){
                return i;
            }
        }
        return 0;
    }
};

// Auto-commit update
