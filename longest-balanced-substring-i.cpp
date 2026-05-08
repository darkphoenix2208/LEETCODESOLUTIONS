// Problem  : Longest Balanced Substring I
// Difficulty: Medium
// Tags     : Hash Table, String, Counting, Enumeration
// URL      : https://leetcode.com/problems/longest-balanced-substring-i/
// Solved on: 2026-04-08 23:53
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int best = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            int distinct = 0, maxFreq = 0;

            for (int j = i; j < n; j++) {
                int idx = s[j] - 'a';

                if (freq[idx] == 0) distinct++;
                freq[idx]++;

                maxFreq = max(maxFreq, freq[idx]);

                int len = j - i + 1;

                if (len == distinct * maxFreq) {
                    best = max(best, len);
                }
            }
        }

        return best;
    }
};

// Auto-commit update
