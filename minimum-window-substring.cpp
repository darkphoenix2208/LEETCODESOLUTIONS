// Problem  : Minimum Window Substring
// Difficulty: Hard
// Tags     : Hash Table, String, Sliding Window
// URL      : https://leetcode.com/problems/minimum-window-substring/
// Solved on: 2026-04-09 00:17
// ──────────────────────────────────────────────────

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        unordered_map<char, int> freq;
        for (char ch : t) freq[ch]++;

        int left = 0, right = 0, start = 0;
        int minLen = INT_MAX;
        int required = t.size();

        while (right < s.size()) {
            if (freq[s[right]] > 0) required--;
            freq[s[right]]--;
            right++;

            while (required == 0) {
                if (right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }

                freq[s[left]]++;
                if (freq[s[left]] > 0) required++;
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};


// Auto-commit update
