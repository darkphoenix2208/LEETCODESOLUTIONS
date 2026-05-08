// Problem  : Delete Columns to Make Sorted
// Difficulty: Easy
// Tags     : Array, String
// URL      : https://leetcode.com/problems/delete-columns-to-make-sorted/
// Solved on: 2026-04-09 00:02
// ──────────────────────────────────────────────────

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count = 0;
        int r = strs.size(), c = strs[0].size();
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < r - 1; j++) {
                if (strs[j][i] > strs[j + 1][i]) {count++; break;}
            }
        }
        return count;
    }
};

// Auto-commit update
