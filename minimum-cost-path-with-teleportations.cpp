// Problem  : Minimum Cost Path with Teleportations
// Difficulty: Hard
// Tags     : Array, Dynamic Programming, Matrix
// URL      : https://leetcode.com/problems/minimum-cost-path-with-teleportations/
// Solved on: 2026-04-09 00:15
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        using ll = long long;
        const ll INF = 4e18;
        int rows = grid.size(), cols = grid[0].size();

        auto dp_step = [&](const vector<vector<ll>>& prev) {
            vector<vector<ll>> next(rows, vector<ll>(cols, INF));
            for (int r = 0; r < rows; ++r) {
                for (int c = 0; c < cols; ++c) {
                    ll best = prev[r][c];
                    if (r > 0) best = min(best, next[r - 1][c] + grid[r][c]);
                    if (c > 0) best = min(best, next[r][c - 1] + grid[r][c]);
                    next[r][c] = best;
                }
            }
            return next;
        };

        vector<vector<ll>> curr(rows, vector<ll>(cols, INF));
        curr[0][0] = 0;
        curr = dp_step(curr);

        unordered_map<int, vector<pair<int, int>>> byValue;
        vector<int> valueKeys;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                int val = grid[r][c];
                if (byValue.find(val) == byValue.end()) valueKeys.push_back(val);
                byValue[val].emplace_back(r, c);
            }
        }

        sort(valueKeys.begin(), valueKeys.end(), greater<int>());

        for (int iter = 0; iter < k; ++iter) {
            vector<vector<ll>> stage(rows, vector<ll>(cols, INF));
            ll globalMin = INF;
            for (int val : valueKeys) {
                ll groupMin = INF;
                for (auto& [r, c] : byValue[val]) {
                    groupMin = min(groupMin, curr[r][c]);
                }
                globalMin = min(globalMin, groupMin);
                for (auto& [r, c] : byValue[val]) {
                    stage[r][c] = globalMin;
                }
            }
            auto updated = dp_step(stage);
            for (int r = 0; r < rows; ++r) {
                for (int c = 0; c < cols; ++c) {
                    curr[r][c] = min(curr[r][c], updated[r][c]);
                }
            }
        }

        return (int)curr[rows - 1][cols - 1];
    }
};


// Auto-commit update
