// Problem  : Find a Peak Element II
// Difficulty: Medium
// Tags     : Array, Binary Search, Matrix
// URL      : https://leetcode.com/problems/find-a-peak-element-ii/
// Solved on: 2026-04-09 00:17
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0, high = m - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Find the row with the maximum element in the mid column
            int maxRow = 0;
            for (int i = 0; i < n; i++) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }

            // Check if mid column max is a peak
            bool leftIsSmaller = (mid == 0 || mat[maxRow][mid] > mat[maxRow][mid - 1]);
            bool rightIsSmaller = (mid == m - 1 || mat[maxRow][mid] > mat[maxRow][mid + 1]);

            if (leftIsSmaller && rightIsSmaller) {
                return {maxRow, mid}; // Found peak
            }
            else if (mid > 0 && mat[maxRow][mid - 1] > mat[maxRow][mid]) {
                high = mid - 1; // Move left
            } else {
                low = mid + 1; // Move right
            }
        }

        return {-1, -1}; // Should never reach here if input has a peak
    }
};


// Auto-commit update
