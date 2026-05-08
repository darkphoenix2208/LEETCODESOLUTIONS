// Problem  : Minimum Deletions to Make String Balanced
// Difficulty: Medium
// Tags     : String, Dynamic Programming, Stack
// URL      : https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/
// Solved on: 2026-04-08 23:53
// ──────────────────────────────────────────────────

class Solution {
public:
    int minimumDeletions(string s) {
        int res = 0, b = 0;

        for (auto& c : s) {
            if (~c & 1) b++;
            else if (b) {
                res++;
                b--;
            }
        }

        return res;
    }
};


// Auto-commit update
