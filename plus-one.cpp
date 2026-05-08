// Problem  : Plus One
// Difficulty: Easy
// Tags     : Array, Math
// URL      : https://leetcode.com/problems/plus-one/
// Solved on: 2026-04-09 00:01
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        int i = d.size() - 1;
        while (i >= 0 && d[i] == 9) {
            d[i] = 0;
            i--;
        }
        if (i >= 0) {
            d[i]++;
        } else {
            d.insert(d.begin(), 1);
        }
        return d;
    }
};

// Auto-commit update
