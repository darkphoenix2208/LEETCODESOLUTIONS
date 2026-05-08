// Problem  : Swim in Rising Water
// Difficulty: Hard
// Tags     : Array, Binary Search, Depth-First Search, Breadth-First Search, Union-Find, Heap (Priority Queue), Matrix
// URL      : https://leetcode.com/problems/swim-in-rising-water/
// Solved on: 2026-04-09 00:09
// ──────────────────────────────────────────────────

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        pq.emplace(grid[0][0], 0, 0);
        vector<int> dirs = {0, 1, 0, -1, 0};

        while (!pq.empty()) {
            auto [t, x, y] = pq.top();
            pq.pop();
            if (visited[x][y]) continue;
            visited[x][y] = true;
            if (x == n - 1 && y == n - 1) return t;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dirs[i], ny = y + dirs[i + 1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny]) {
                    pq.emplace(max(t, grid[nx][ny]), nx, ny);
                }
            }
        }
        return -1;
    }
};


// Auto-commit update
