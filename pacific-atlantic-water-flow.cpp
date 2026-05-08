// Problem  : Pacific Atlantic Water Flow
// Difficulty: Medium
// Tags     : Array, Depth-First Search, Breadth-First Search, Matrix
// URL      : https://leetcode.com/problems/pacific-atlantic-water-flow/
// Solved on: 2026-04-09 00:10
// ──────────────────────────────────────────────────

class Solution {
public:
    int m, n;
    vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
    
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int i, int j) {
        ocean[i][j] = true;
        for (auto& d : dirs) {
            int x = i + d[0], y = j + d[1];
            if (x < 0 || x >= m || y < 0 || y >= n || ocean[x][y] || heights[x][y] < heights[i][j])
                continue;
            dfs(heights, ocean, x, y);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; ++i) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, n - 1);
        }
        for (int j = 0; j < n; ++j) {
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, m - 1, j);
        }
        
        vector<vector<int>> result;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};


// Auto-commit update
