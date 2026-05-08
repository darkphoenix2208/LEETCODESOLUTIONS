// Problem  : Triangle
// Difficulty: Medium
// Tags     : Array, Dynamic Programming
// URL      : https://leetcode.com/problems/triangle/
// Solved on: 2026-04-09 00:10
// ──────────────────────────────────────────────────

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
    
        for (int row = n - 2; row >= 0; --row) {
            for (int col = 0; col < triangle[row].size(); ++col) {
                triangle[row][col] += min(triangle[row + 1][col], triangle[row + 1][col + 1]);
            }
        }
        
        return triangle[0][0]; 
    }
};


// Auto-commit update
