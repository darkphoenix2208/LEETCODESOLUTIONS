// Problem  : Compare Version Numbers
// Difficulty: Medium
// Tags     : Two Pointers, String
// URL      : https://leetcode.com/problems/compare-version-numbers/
// Solved on: 2026-04-09 00:10
// ──────────────────────────────────────────────────

class Solution {
public:
    int compareVersion(string a, string b) {
        int i = 0, j = 0;
        int n = a.size(), m = b.size();

        while (i < n || j < m) {
            string s1 = "";
            string s2 = "";

            while (i < n && a[i] != '.') {
                s1 += a[i];
                i++;
            }
            if (i < n && a[i] == '.') i++;

            while (j < m && b[j] != '.') {
                s2 += b[j];
                j++;
            }
            if (j < m && b[j] == '.') j++;

            int x = s1.empty() ? 0 : stoi(s1);
            int y = s2.empty() ? 0 : stoi(s2);

            if (x < y) return -1;
            if (x > y) return 1;
        }
        return 0;
    }
};


// Auto-commit update
