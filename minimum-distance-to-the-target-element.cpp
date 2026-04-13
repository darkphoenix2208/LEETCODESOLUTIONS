// Problem  : Minimum Distance to the Target Element
// Difficulty: Easy
// Tags     : Array
// URL      : https://leetcode.com/problems/minimum-distance-to-the-target-element/
// Solved on: 2026-05-08 21:48
// ──────────────────────────────────────────────────

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int res = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                res = min(res, abs(i - start));
            }
        }
        return res;
    }
};

// Auto-commit update
