// Problem  : Maximum Square Area by Removing Fences From a Field
// Difficulty: Medium
// Tags     : Array, Hash Table, Enumeration
// URL      : https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field/
// Solved on: 2026-04-08 23:57
// ──────────────────────────────────────────────────

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
        const int MOD = 1e9 + 7;

        h.push_back(1);
        h.push_back(m);
        v.push_back(1);
        v.push_back(n);

        sort(h.begin(), h.end());
        sort(v.begin(), v.end());

        unordered_set<int> s;
        int x = h.size(), y = v.size();

        for (int i = 0; i < x; i++) {
            for (int j = i + 1; j < x; j++) {
                s.insert(h[j] - h[i]);
            }
        }

        long long ans = -1;
        for (int i = 0; i < y; i++) {
            for (int j = i + 1; j < y; j++) {
                int d = v[j] - v[i];
                if (s.count(d)) {
                    ans = max(ans, (long long)d * d);
                }
            }
        }

        if (ans == -1) return -1;
        return ans % MOD;
    }
};

// Auto-commit update
