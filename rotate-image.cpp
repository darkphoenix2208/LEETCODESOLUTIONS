// Problem  : Rotate Image
// Difficulty: Medium
// Tags     : Array, Math, Matrix
// URL      : https://leetcode.com/problems/rotate-image/
// Solved on: 2026-05-08 21:47
// ──────────────────────────────────────────────────

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++){
for(int j=i+1;j<n;j++){
    swap(matrix[i][j],matrix[j][i]);
}
        }

      for (int i = 0; i < n; ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
        
    }
};

// Auto-commit update
