// Problem  : Number of Operations to Make Network Connected
// Difficulty: Medium
// Tags     : Depth-First Search, Breadth-First Search, Union-Find, Graph Theory
// URL      : https://leetcode.com/problems/number-of-operations-to-make-network-connected/
// Solved on: 2026-04-08 23:56
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> parent, sz;

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]); 
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;

        if (sz[a] < sz[b])
            swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1;

        parent.resize(n);
        sz.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (auto &e : connections)
            unite(e[0], e[1]);

        int components = 0;
        for (int i = 0; i < n; i++) {
            if (find(i) == i)
                components++;
        }

        return components - 1;
    }
};


// Auto-commit update
