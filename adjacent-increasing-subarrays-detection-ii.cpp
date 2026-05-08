// Problem  : Adjacent Increasing Subarrays Detection II
// Difficulty: Medium
// Tags     : Array, Binary Search
// URL      : https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/
// Solved on: 2026-04-09 00:09
// ──────────────────────────────────────────────────

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int cnt = 1, precnt = 0, ans = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                ++cnt;
            } else {
                precnt = cnt;
                cnt = 1;
            }
            ans = max(ans, min(precnt, cnt));
            ans = max(ans, cnt / 2);
        }
        return ans;
    }
};

// Auto-commit update
