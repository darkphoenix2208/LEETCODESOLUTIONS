// Problem  : Construct the Minimum Bitwise Array II
// Difficulty: Medium
// Tags     : Array, Bit Manipulation
// URL      : https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/
// Solved on: 2026-04-08 23:57
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int N = nums.size();
        vector<int> Ans(N, -1);

        for (int i = 0; i < N; i++) {
            if (nums[i] == 2) continue;

            int n = nums[i];
            int pos = 0;

    
            while (n > 0 && ((n >> pos) & 1) == 1) {
                pos++;
            }

    
            if ((1 << pos) > n) {
                int highestBit = 31 - __builtin_clz(n);
                n = n & ~(1 << highestBit);
            }

            else {
                n = n & ~(1 << (pos - 1));
            }

            Ans[i] = n;
        }

        return Ans;
    }
};

// Auto-commit update
