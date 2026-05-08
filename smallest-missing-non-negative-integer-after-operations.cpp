// Problem  : Smallest Missing Non-negative Integer After Operations
// Difficulty: Medium
// Tags     : Array, Hash Table, Math, Greedy
// URL      : https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/
// Solved on: 2026-04-09 00:09
// ──────────────────────────────────────────────────

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> freq;

        
        for (int num : nums) {
            int mod = ((num % value) + value) % value;
            freq[mod]++;
        }
        for (int mex = 0; ; mex++) {
            int mod = mex % value;

            
            if (freq[mod] > 0) {
                freq[mod]--;
            } 
            else{
                return mex;
            }
        }
    }
};

// Auto-commit update
