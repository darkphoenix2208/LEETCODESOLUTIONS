// Problem  : Construct the Minimum Bitwise Array I
// Difficulty: Easy
// Tags     : Array, Bit Manipulation
// URL      : https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/
// Solved on: 2026-04-08 23:57
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int x : nums) {
            int best = -1;

            for (int a = 0; a < x; a++) {
                if ((a | (a + 1)) == x) {
                    best = a;
               break;
                }
            }

            ans.push_back(best);
        }

        return ans;
    }
};

// Auto-commit update
