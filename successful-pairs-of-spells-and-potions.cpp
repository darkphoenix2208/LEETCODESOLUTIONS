// Problem  : Successful Pairs of Spells and Potions
// Difficulty: Medium
// Tags     : Array, Two Pointers, Binary Search, Sorting
// URL      : https://leetcode.com/problems/successful-pairs-of-spells-and-potions/
// Solved on: 2026-04-09 00:09
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> res;
        int m = potions.size();
        for (int spell : spells) {
            long long minPotion = (success + spell - 1) / spell;
            int idx = lower_bound(potions.begin(), potions.end(), minPotion) - potions.begin();
            res.push_back(m - idx);
        }
        return res;
    }
};


// Auto-commit update
