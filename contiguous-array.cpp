// Problem  : Contiguous Array
// Difficulty: Medium
// Tags     : Array, Hash Table, Prefix Sum
// URL      : https://leetcode.com/problems/contiguous-array/
// Solved on: 2026-04-09 00:19
// ──────────────────────────────────────────────────

class Solution {
public:
   int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> mp;
    mp[0] = -1; // sum 0 occurs at index -1 (important base case)
    int sum = 0, maxLen = 0;

    for (int i = 0; i < nums.size(); ++i) {
        sum += (nums[i] == 1 ? 1 : -1); // treat 1 as +1, 0 as -1

        if (mp.count(sum)) {
            maxLen = max(maxLen, i - mp[sum]);
        } else {
            mp[sum] = i; // store the first occurrence of this sum
        }
    }

    return maxLen;
}

};

// Auto-commit update
