// Problem  : Trionic Array I
// Difficulty: Easy
// Tags     : Array
// URL      : https://leetcode.com/problems/trionic-array-i/
// Solved on: 2026-04-08 23:54
// ──────────────────────────────────────────────────

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int peak = -1;
        int valley = n;

        for (int i = 0; i < n - 1; i++) {
            if (peak == -1 && nums[i] >= nums[i + 1])
                peak = i;
            
            if (valley == n && nums[n - 1 - i] <= nums[n - 2 - i])
                valley = n - 1 - i;
            
            if (peak > -1 && valley < n) break;
        }

        if (peak < 1 || valley > n - 2)
            return false;

        for (int i = peak; i < valley; i++)
            if (nums[i] <= nums[i + 1])
                return false;

        return true;
    }
};

// Auto-commit update
