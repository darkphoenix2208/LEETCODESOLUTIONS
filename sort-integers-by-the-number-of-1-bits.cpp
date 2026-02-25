// Problem  : Sort Integers by The Number of 1 Bits
// Difficulty: Easy
// Tags     : Array, Bit Manipulation, Sorting, Counting
// URL      : https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
// Solved on: 2026-05-08 21:52
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        
        vector<vector<int>> bucket(15); 
        

        for(int num : arr) {
            int bits = __builtin_popcount(num);
            bucket[bits].push_back(num);
        }
        
        
        for(int i = 0; i < 15; i++) {
            sort(bucket[i].begin(), bucket[i].end());
        }
        
        
        vector<int> ans;
        for(int i = 0; i < 15; i++) {
            for(int num : bucket[i]) {
                ans.push_back(num);
            }
        }
        
        return ans;
    }
};

// Auto-commit update
