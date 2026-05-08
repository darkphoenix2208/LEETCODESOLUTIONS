// Problem  : Search a 2D Matrix
// Difficulty: Medium
// Tags     : Array, Binary Search, Matrix
// URL      : https://leetcode.com/problems/search-a-2d-matrix/
// Solved on: 2026-04-09 00:18
// ──────────────────────────────────────────────────

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int rows = matrix.size();
        int cols = matrix[0].size();
        int low = 0;
        int high = rows * cols - 1;  // ✅ fix here

        while (low <= high) {
            int mid = (low + high) / 2;
            int row = mid / cols;
            int col = mid % cols;

            if (matrix[row][col] < target) {
                low = mid + 1;
            } else if (matrix[row][col] > target) {
                high = mid - 1;
            } else {
                return true;
            }
        }

        return false;
    }
};


// Auto-commit update
