// Problem  : Cheapest Flights Within K Stops
// Difficulty: Medium
// Tags     : Dynamic Programming, Depth-First Search, Breadth-First Search, Graph Theory, Heap (Priority Queue), Shortest Path
// URL      : https://leetcode.com/problems/cheapest-flights-within-k-stops/
// Solved on: 2026-04-08 23:55
// ──────────────────────────────────────────────────

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);
        for (auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        vector<int> dist(n, 1e9);
        queue<pair<int,int>> q;

        q.push({src, 0});
        dist[src] = 0;

        int stops = 0;

        while (!q.empty() && stops <= k) {
            int sz = q.size();
            while (sz--) {
                auto [node, cost] = q.front();
                q.pop();

                for (auto &it : adj[node]) {
                    int next = it.first;
                    int price = it.second;

                    if (cost + price < dist[next]) {
                        dist[next] = cost + price;
                        q.push({next, dist[next]});
                    }
                }
            }
            stops++;
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};


// Auto-commit update
