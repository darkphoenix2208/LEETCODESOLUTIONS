// Problem  : Count the Number of Computer Unlocking Permutations
// Difficulty: Medium
// Tags     : Array, Math, Brainteaser, Combinatorics
// URL      : https://leetcode.com/problems/count-the-number-of-computer-unlocking-permutations/
// Solved on: 2026-04-09 00:02
// ──────────────────────────────────────────────────

class Solution {
public:
    static const int MOD = 1000000007;

    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        int first = complexity[0];

        for (int i = 1; i < n; i++) {
            if (complexity[i] <= first) return 0;
        }

        long long fact = 1;
        for (int i = 2; i < n; i++) {
            fact = (fact * i) % MOD;
        }

        return (int)fact;
    }
};

// Auto-commit update
