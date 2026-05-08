// Problem  : Rotting Oranges
// Difficulty: Medium
// Tags     : Array, Breadth-First Search, Matrix
// URL      : https://leetcode.com/problems/rotting-oranges/
// Solved on: 2026-04-09 00:05
// ──────────────────────────────────────────────────

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        int m = grid.size(), n = grid[0].size();
        int days = 0, tot = 0, cnt = 0;
        queue<pair<int, int>> rotten;

    
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 0) tot++;
                if (grid[i][j] == 2) rotten.push({i, j});
            }
        }

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        while (!rotten.empty()) {
            int k = rotten.size();
            cnt += k;

            while (k--) {
                int x = rotten.front().first;
                int y = rotten.front().second;
                rotten.pop();

                for (int i = 0; i < 4; ++i) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1)
                        continue;

                    grid[nx][ny] = 2;
                    rotten.push({nx, ny});
                }
            }

            if (!rotten.empty()) days++;
        }

        return tot == cnt ? days : -1;
    }
};


// Auto-commit update
