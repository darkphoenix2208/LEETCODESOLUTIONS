// Problem  : Sort Matrix by Diagonals
// Difficulty: Medium
// Tags     : Array, Sorting, Matrix
// URL      : https://leetcode.com/problems/sort-matrix-by-diagonals/
// Solved on: 2026-04-09 00:14
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int j = 0;
        for (int i = 0; i < n; i++) {
            vector<int> t;
            int a = i;
            while (a < n) {
                t.push_back(grid[a][j]);
                a++;
                j++;
            }
            a = i;
            j = 0;
            sort(t.begin(), t.end(), greater<int>());
            int c = 0; 
            while (a < n) {
                grid[a][j] = t[c];
                c++;
                a++;
                j++;
            }
            j = 0;
        }
        for (int i = 1; i < n; i++) {
            vector<int> t;
            int a = i;
            while (a < n) {
                t.push_back(grid[j][a]);
                a++;
                j++;
            }
            a = i;
            j = 0;
            sort(t.begin(), t.end());
            int c = 0; 
            while (a < n) {
                grid[j][a] = t[c];
                c++;
                a++;
                j++;
            }
            j = 0;
        }

        return grid;
    }
};


// Auto-commit update
