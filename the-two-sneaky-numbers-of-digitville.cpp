// Problem  : The Two Sneaky Numbers of Digitville
// Difficulty: Easy
// Tags     : Array, Hash Table, Math
// URL      : https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/
// Solved on: 2026-04-09 00:05
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> freq;
        vector<int> res;
        for (int x : nums) freq[x]++;
        for (auto &p : freq)
            if (p.second > 1) res.push_back(p.first);
        return res;
    }
};

// Auto-commit update
