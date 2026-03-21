// Problem  : Flip Square Submatrix Vertically
// Difficulty: Easy
// Tags     : Array, Two Pointers, Matrix
// URL      : https://leetcode.com/problems/flip-square-submatrix-vertically/
// Solved on: 2026-05-08 21:50
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
       int cnt=0;
       int a=k/2;
        for(int i=x;i<x+a;i++){
          for(int j=y;j<y+k;j++){
            swap(grid[i][j],grid[x+k-cnt-1][j]);
          }
          cnt++;
        }
        return grid;
    }
};

// Auto-commit update
