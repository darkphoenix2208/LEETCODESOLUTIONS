// Problem  : Keep Multiplying Found Values by Two
// Difficulty: Easy
// Tags     : Array, Hash Table, Sorting, Simulation
// URL      : https://leetcode.com/problems/keep-multiplying-found-values-by-two/
// Solved on: 2026-04-09 00:04
// ──────────────────────────────────────────────────

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        for (int num : nums) {
            if (original == num) {
                original *= 2;
            }
        }
        return original;
    }
};

// Auto-commit update
