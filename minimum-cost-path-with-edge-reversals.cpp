// Problem  : Minimum Cost Path with Edge Reversals
// Difficulty: Medium
// Tags     : Graph Theory, Heap (Priority Queue), Shortest Path
// URL      : https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/
// Solved on: 2026-04-09 00:15
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        using ll = long long;
        const ll INF = 1e18;

        vector<vector<pair<int, int>>> G(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1], c = e[2];
            G[a].push_back({b, c});
            G[b].push_back({a, 2 * c});
        }

        vector<ll> D(n, INF);
        D[0] = 0;

        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> Q;
        Q.push({0, 0});

        while (!Q.empty()) {
            auto [cost, node] = Q.top();
            Q.pop();
            if (cost > D[node]) continue;
            if (node == n - 1) break;
            for (auto& [nbr, wt] : G[node]) {
                ll alt = cost + wt;
                if (alt < D[nbr]) {
                    D[nbr] = alt;
                    Q.push({alt, nbr});
                }
            }
        }

        return D[n - 1] >= INF / 2 ? -1 : (int)D[n - 1];
    }
};


// Auto-commit update
