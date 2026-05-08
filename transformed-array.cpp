// Problem  : Transformed Array
// Difficulty: Easy
// Tags     : Array, Simulation
// URL      : https://leetcode.com/problems/transformed-array/
// Solved on: 2026-04-08 23:54
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> r(n);

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                r[i] = nums[(i + nums[i]) % n];
            }
            else if (nums[i] == 0) {
                r[i] = 0;
            }
            else {
                r[i] = nums[((i + nums[i]) % n + n) % n];
            }
        }
        return r;
    }
};


// Auto-commit update
