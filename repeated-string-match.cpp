// Problem  : Repeated String Match
// Difficulty: Medium
// Tags     : String, String Matching
// URL      : https://leetcode.com/problems/repeated-string-match/
// Solved on: 2026-04-09 00:16
// ──────────────────────────────────────────────────

class Solution {
public:
    const int BASE = 31;
    const int MOD = 1e9 + 9;

    // Rabin-Karp implementation to check if pattern exists in text
    bool rabinKarp(const string& text, const string& pattern) {
        int n = text.size();
        int m = pattern.size();
        if (m > n) return false;

        // Precompute powers of BASE
        vector<long long> power(m);
        power[0] = 1;
        for (int i = 1; i < m; i++) {
            power[i] = (power[i - 1] * BASE) % MOD;
        }

        // Compute pattern hash
        long long patternHash = 0;
        for (int i = 0; i < m; i++) {
            patternHash = (patternHash * BASE + (pattern[i] - 'a' + 1)) % MOD;
        }

        // Compute initial hash of text window
        long long windowHash = 0;
        for (int i = 0; i < m; i++) {
            windowHash = (windowHash * BASE + (text[i] - 'a' + 1)) % MOD;
        }

        if (windowHash == patternHash && text.substr(0, m) == pattern)
            return true;

        // Slide the window
        for (int i = m; i < n; i++) {
            // Remove leftmost character
            windowHash = (windowHash - (text[i - m] - 'a' + 1) * power[m - 1]) % MOD;
            if (windowHash < 0) windowHash += MOD;

            // Add new character
            windowHash = (windowHash * BASE + (text[i] - 'a' + 1)) % MOD;

            if (windowHash == patternHash) {
                if (text.substr(i - m + 1, m) == pattern)
                    return true;
            }
        }

        return false;
    }

    int repeatedStringMatch(string a, string b) {
        if (a == b) return 1;

        string s = a;
        int count = 1;

        // Repeat until s length >= b length
        while (s.length() < b.length()) {
            s += a;
            count++;
        }

        // Check if b is a substring in current or next repeat
        if (rabinKarp(s, b)) return count;
        s += a;
        if (rabinKarp(s, b)) return count + 1;

        return -1; // not found
    }
};


// Auto-commit update
