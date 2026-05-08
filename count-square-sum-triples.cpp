// Problem  : Count Square Sum Triples
// Difficulty: Easy
// Tags     : Math, Enumeration
// URL      : https://leetcode.com/problems/count-square-sum-triples/
// Solved on: 2026-04-09 00:02
// ──────────────────────────────────────────────────

class Solution {
public:
    int countTriples(int n) {
        int res = 0;
        for (int u = 2; u <= sqrt(n); u++) {
            for (int v = 1; v < u; v++) {
                if (~(u - v) & 1 || gcd(u, v) != 1) continue;
                int c = u * u + v * v;
                if (c > n) continue;
                res += 2 * (n / c);
            }
        }
        return res;
    }
};


// Auto-commit update
