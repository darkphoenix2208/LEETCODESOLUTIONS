// Problem  : Detect Cycles in 2D Grid
// Difficulty: Medium
// Tags     : Array, Depth-First Search, Breadth-First Search, Union-Find, Matrix
// URL      : https://leetcode.com/problems/detect-cycles-in-2d-grid/
// Solved on: 2026-05-08 21:47
// ──────────────────────────────────────────────────

class Solution {
public:
    int n,m;
    vector<vector<int>> vis;

    bool dfs(int x,int y,int px,int py,vector<vector<char>>& g){
        vis[x][y]=1;

        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};

        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx<0||ny<0||nx>=n||ny>=m) continue;
            if(g[nx][ny]!=g[x][y]) continue;

            if(!vis[nx][ny]){
                if(dfs(nx,ny,x,y,g)) return true;
            }
            else if(nx!=px || ny!=py){
                return true;
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& g) {
        n=g.size();
        m=g[0].size();
        vis.assign(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    if(dfs(i,j,-1,-1,g)) return true;
                }
            }
        }
        return false;
    }
};

// Auto-commit update
