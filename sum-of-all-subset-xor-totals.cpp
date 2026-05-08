// Problem  : Sum of All Subset XOR Totals
// Difficulty: Easy
// Tags     : Array, Math, Backtracking, Bit Manipulation, Combinatorics, Enumeration
// URL      : https://leetcode.com/problems/sum-of-all-subset-xor-totals/
// Solved on: 2026-04-09 00:14
// ──────────────────────────────────────────────────

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;

        for (int mask = 0; mask < (1 << n); mask++) {
            int xr = 0;  
            for (int j = 0; j < n; j++) {
                if (mask & (1 << j)) {  
                    xr ^= nums[j];
                }
            }
            total += xr;
        }
        return total;
    }
};


// Auto-commit update
