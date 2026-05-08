// Problem  : Longest Repeating Character Replacement
// Difficulty: Medium
// Tags     : Hash Table, String, Sliding Window
// URL      : https://leetcode.com/problems/longest-repeating-character-replacement/
// Solved on: 2026-04-09 00:17
// ──────────────────────────────────────────────────

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int l = 0, r = 0, maxCount = 0, res = 0;

        while (r < s.size()) {
            mp[s[r]]++;
            maxCount = max(maxCount, mp[s[r]]); // most frequent char count

            // Window size - maxFreq > k => shrink the window
            if ((r - l + 1) - maxCount > k) {
                mp[s[l]]--;
                l++;
            }

            res = max(res, r - l + 1);
            r++;
        }

        return res;
    }
};


// Auto-commit update
