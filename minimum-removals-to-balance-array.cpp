// Problem  : Minimum Removals to Balance Array
// Difficulty: Medium
// Tags     : Array, Binary Search, Sliding Window, Sorting
// URL      : https://leetcode.com/problems/minimum-removals-to-balance-array/
// Solved on: 2026-04-08 23:54
// ──────────────────────────────────────────────────

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        int maxLen = 0;
        
        for (int j = 0; j < n; j++) {
            while ((long long)nums[j] > (long long)nums[i] * k) {
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
        }
        
        return n - maxLen;
    }
};

// Auto-commit update
