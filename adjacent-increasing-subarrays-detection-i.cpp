// Problem  : Adjacent Increasing Subarrays Detection I
// Difficulty: Easy
// Tags     : Array
// URL      : https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/
// Solved on: 2026-04-09 00:09
// ──────────────────────────────────────────────────

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i + 2 * k <= n; ++i) {
            bool first = true, second = true;
            for (int j = i + 1; j < i + k; ++j) {
                if (nums[j] <= nums[j - 1]) {
                    first = false;
                    break;
                }
            }
            if (!first) continue;
            for (int j = i + k + 1; j < i + 2 * k; ++j) {
                if (nums[j] <= nums[j - 1]) {
                    second = false;
                    break;
                }
            }
            if (second) return true;
        }
        return false;
    }
};


// Auto-commit update
