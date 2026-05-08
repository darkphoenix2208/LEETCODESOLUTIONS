// Problem  : Spiral Matrix
// Difficulty: Medium
// Tags     : Array, Matrix, Simulation
// URL      : https://leetcode.com/problems/spiral-matrix/
// Solved on: 2026-04-09 00:17
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> a;
        int n = matrix.size();
        int m = matrix[0].size(); 
        int top = 0, left = 0, bottom = n - 1, right = m - 1;

        while (top <= bottom && left <= right) {
            // Traverse from left to right
            for (int i = left; i <= right; i++)
                a.push_back(matrix[top][i]);
            top++;

            // Traverse from top to bottom
            for (int i = top; i <= bottom; i++)
                a.push_back(matrix[i][right]);
            right--;

            // Traverse from right to left
            if (top <= bottom) {
                for (int i = right; i >= left; i--)
                    a.push_back(matrix[bottom][i]);
                bottom--;
            }

            // Traverse from bottom to top
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    a.push_back(matrix[i][left]);
                left++;
            }
        }
        return a;
    }
};


// Auto-commit update
