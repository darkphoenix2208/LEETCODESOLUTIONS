// Problem  : Maximum Area of Longest Diagonal Rectangle
// Difficulty: Easy
// Tags     : Array
// URL      : https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle/
// Solved on: 2026-04-09 00:14
// ──────────────────────────────────────────────────

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxDiag = 0;
        int maxArea = 0;

        for (int i = 0; i < dimensions.size(); i++) {
            int l = dimensions[i][0];
            int w = dimensions[i][1];

            double diag = sqrt(1.0 * l * l + 1.0 * w * w);
            int area = l * w;

            if (diag > maxDiag || (fabs(diag - maxDiag) < 1e-9 && area > maxArea)) {
                maxDiag = diag;
                maxArea = area;
            }
        }
        return maxArea;
    }
};


// Auto-commit update
