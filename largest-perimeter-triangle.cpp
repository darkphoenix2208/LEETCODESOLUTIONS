// Problem  : Largest Perimeter Triangle
// Difficulty: Easy
// Tags     : Array, Math, Greedy, Sorting
// URL      : https://leetcode.com/problems/largest-perimeter-triangle/
// Solved on: 2026-04-09 00:10
// ──────────────────────────────────────────────────

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        int n = nums.size();
        
        for (int i = n - 1; i >= 2; i--) {
            int a = nums[i - 2], b = nums[i - 1], c = nums[i];
            if (a + b > c) {
                return a + b + c; 
            }
        }
        return 0; 
    }
};


// Auto-commit update
