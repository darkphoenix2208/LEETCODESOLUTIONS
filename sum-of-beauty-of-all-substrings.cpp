// Problem  : Sum of Beauty of All Substrings
// Difficulty: Medium
// Tags     : Hash Table, String, Counting
// URL      : https://leetcode.com/problems/sum-of-beauty-of-all-substrings/
// Solved on: 2026-04-09 00:16
// ──────────────────────────────────────────────────

class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int totalBeauty = 0;

        // Fix start index of substring
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0); // reset freq for each new start

            // Expand end index
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                // Find min & max freq among current substring
                int minFreq = INT_MAX, maxFreq = INT_MIN;
                for (int f : freq) {
                    if (f > 0) { // consider only chars present
                        minFreq = min(minFreq, f);
                        maxFreq = max(maxFreq, f);
                    }
                }

                totalBeauty += (maxFreq - minFreq);
            }
        }

        return totalBeauty;
    }
};


// Auto-commit update
