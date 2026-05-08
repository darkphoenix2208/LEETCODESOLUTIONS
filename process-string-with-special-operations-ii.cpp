// Problem  : Process String with Special Operations II
// Difficulty: Hard
// Tags     : String, Simulation
// URL      : https://leetcode.com/problems/process-string-with-special-operations-ii/
// Solved on: 2026-04-09 00:16
// ──────────────────────────────────────────────────

class Solution {
public:
    char processStr(string s, long long k) {
        string tibrelkano = s;
        int n = tibrelkano.size();
        vector<long long> len(n);
        long long cur = 0;
        for (int i = 0; i < n; ++i) {
            char c = tibrelkano[i];
            if (c >= 'a' && c <= 'z') {
                cur += 1;
            } else if (c == '*') {
                if (cur > 0) cur -= 1;
            } else if (c == '#') {
                cur = cur * 2;
            } else if (c == '%') {
                /* length unchanged */
            }
            if (cur > (long long)1e15) cur = (long long)1e15 + 1;
            len[i] = cur;
        }
        if (k >= cur) return '.';
        for (int i = n - 1; i >= 0; --i) {
            char c = tibrelkano[i];
            long long prev = (i == 0 ? 0 : len[i - 1]);
            if (c >= 'a' && c <= 'z') {
                if (k == len[i] - 1) return c;
                /* else continue */
            } else if (c == '*') {
                /* k unchanged */
            } else if (c == '#') {
                if (k >= prev) k -= prev;
            } else if (c == '%') {
                k = len[i] - 1 - k;
            }
        }
        return '.';
    }
};

// Auto-commit update
