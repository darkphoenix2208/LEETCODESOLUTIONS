// Problem  : Binary Prefix Divisible By 5
// Difficulty: Easy
// Tags     : Array, Bit Manipulation
// URL      : https://leetcode.com/problems/binary-prefix-divisible-by-5/
// Solved on: 2026-04-09 00:04
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> answer;
        int prefix = 0;
        int length = nums.size();
        for (int i = 0; i < length; i++) {
            prefix = ((prefix << 1) + nums[i]) % 5;
            answer.emplace_back(prefix == 0);
        }
        return answer;
    }
};

// Auto-commit update
