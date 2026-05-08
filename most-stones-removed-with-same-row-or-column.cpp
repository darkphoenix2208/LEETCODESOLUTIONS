// Problem  : Most Stones Removed with Same Row or Column
// Difficulty: Medium
// Tags     : Hash Table, Depth-First Search, Union-Find, Graph Theory
// URL      : https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
// Solved on: 2026-04-08 23:56
// ──────────────────────────────────────────────────

class Solution {
public:
    unordered_map<int, int> parent;

    int find(int x) {
        if (parent.find(x) == parent.end())
            parent[x] = x;
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }

    int removeStones(vector<vector<int>>& stones) {
        for (auto& stone : stones) {
            unite(stone[0], stone[1] + 10001);
        }

        unordered_set<int> components;
        for (auto& stone : stones) {
            components.insert(find(stone[0]));
        }

        return stones.size() - components.size();
    }
};


// Auto-commit update
