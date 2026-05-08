// Problem  : Unique Length-3 Palindromic Subsequences
// Difficulty: Medium
// Tags     : Hash Table, String, Bit Manipulation, Prefix Sum
// URL      : https://leetcode.com/problems/unique-length-3-palindromic-subsequences/
// Solved on: 2026-04-09 00:04
// ──────────────────────────────────────────────────

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int ans = 0;

        for(char c = 'a'; c <= 'z'; c++) {
            int left = -1, right = -1;

            for(int i = 0; i < n; i++) {
                if(s[i] == c) {
                    if(left == -1) left = i;
                    right = i;
                }
            }

            if(left == -1 || right == -1 || left == right) continue;

            bool seen[26] = {0};
            for(int i = left + 1; i < right; i++) {
                seen[s[i] - 'a'] = true;
            }

            for(int k = 0; k < 26; k++)
                if(seen[k]) ans++;
        }

        return ans;
    }
};


// Auto-commit update
