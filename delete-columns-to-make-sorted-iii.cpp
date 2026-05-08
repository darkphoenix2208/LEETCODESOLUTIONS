// Problem  : Delete Columns to Make Sorted III
// Difficulty: Hard
// Tags     : Array, String, Dynamic Programming
// URL      : https://leetcode.com/problems/delete-columns-to-make-sorted-iii/
// Solved on: 2026-04-09 00:01
// ──────────────────────────────────────────────────

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = (int)strs[0].size();
        int m = (int)strs.size();
        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                bool ok = true;
                for (int r = 0; r < m; r++) {
                    if (strs[r][j] > strs[r][i]) { ok = false; break; }
                }
                if (ok) dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        int mx = 0;
        for (int v : dp) mx = max(mx, v);
        return n - mx;
    }
};

// Auto-commit update
