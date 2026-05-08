// Problem  : 01 Matrix
// Difficulty: Medium
// Tags     : Array, Dynamic Programming, Breadth-First Search, Matrix
// URL      : https://leetcode.com/problems/01-matrix/
// Solved on: 2026-04-09 00:05
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        queue<pair<int,int>> q;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i = 0; i < 4; i++) {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                
                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m) {
                    if(dist[nRow][nCol] > dist[row][col] + 1) {
                        dist[nRow][nCol] = dist[row][col] + 1;
                        q.push({nRow, nCol});
                    }
                }
            }
        }
        
        return dist;
    }
};


// Auto-commit update
