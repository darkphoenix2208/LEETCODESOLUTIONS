// Problem  : Minimum Operations to Make Array Elements Zero
// Difficulty: Hard
// Tags     : Array, Math, Bit Manipulation
// URL      : https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero/
// Solved on: 2026-04-09 00:13
// ──────────────────────────────────────────────────

class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        vector<long long> pows;
        long long v = 1;
        while (v <= 1e9) {
            pows.push_back(v);
            v *= 4;
        }
        pows.push_back(4e18); 

        long long total = 0;

        for (auto &q : queries) {
            long long l = q[0], r = q[1];
            long long sumSteps = 0;
            long long maxStep = 0;

            for (int k = 0; k + 1 < pows.size(); k++) {
                long long left = max(l, pows[k]);
                long long right = min(r, pows[k + 1] - 1);
                if (left > right) continue;

                long long count = right - left + 1;
                long long step = k + 1; 
                sumSteps += count * step;
                maxStep = max(maxStep, step);
            }

            long long ops = max((sumSteps + 1) / 2, maxStep);
            total += ops;
        }
        return total;
    }
};


// Auto-commit update
