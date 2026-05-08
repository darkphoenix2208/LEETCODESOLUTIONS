// Problem  : Shortest Path in Binary Matrix
// Difficulty: Medium
// Tags     : Array, Breadth-First Search, Matrix
// URL      : https://leetcode.com/problems/shortest-path-in-binary-matrix/
// Solved on: 2026-04-08 23:57
// ──────────────────────────────────────────────────

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>p(n,vector<int>(m,1e9));
        if(n==1 && grid[0][0]==0){
            return 1;
        }
    if(grid[0][0]==1){
        return -1;
    }
       queue<pair<int, pair<int, int>>> q;
       p[0][0]=1;
        q.push({0,{0,0}});
        int dr[] = {-1, 0, 1, 0,-1,-1,1,1};
        int dc[] = {0, 1, 0, -1,-1,1,1,-1};
        while(!q.empty()){
        auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            for (int i = 0; i < 8; i++) {
                int newr = r + dr[i];
                int newc = c + dc[i];
                if (newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 0 && dis + 1 < p[newr][newc]) {
                    p[newr][newc] = 1 + dis;  

                    if (newr == n-1 && newc == n-1)
                        return dis + 2;

                    q.push({1 + dis, {newr, newc}});
                }
            }

        }
        return -1;
    }
};

// Auto-commit update
