// Problem  : Find the Minimum Area to Cover All Ones I
// Difficulty: Medium
// Tags     : Array, Matrix
// URL      : https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/
// Solved on: 2026-04-09 00:15
// ──────────────────────────────────────────────────

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int minRow = n, maxRow = -1;
        int minCol = m, maxCol = -1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);
                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }
            }
        }


        if (maxRow == -1) return 0;

        int height = maxRow - minRow + 1;
        int width  = maxCol - minCol + 1;

        return height * width;
    }
};


// Auto-commit update
