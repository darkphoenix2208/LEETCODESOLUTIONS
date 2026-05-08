// Problem  : Minimum Number of Operations to Make All Array Elements Equal to 1
// Difficulty: Medium
// Tags     : Array, Math, Number Theory
// URL      : https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/
// Solved on: 2026-04-09 00:04
// ──────────────────────────────────────────────────

class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int n = nums.size();
        int res = INT_MAX, cnt1 = 0;
        for (int i = 0; i < n; ++i)
            cnt1 += (nums[i] == 1);
        if (cnt1)
            return n - cnt1;
        for (int i = 0; i < n; ++i) {
            int g = nums[i];
            for (int j = i + 1; j < n; ++j) {
                g = __gcd(g, nums[j]);
                if (g == 1) {
                    res = min(res, j - i + n - 1);
                    break;
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};

// Auto-commit update
