// Problem  : Largest Triangle Area
// Difficulty: Easy
// Tags     : Array, Math, Geometry
// URL      : https://leetcode.com/problems/largest-triangle-area/
// Solved on: 2026-04-09 00:10
// ──────────────────────────────────────────────────



class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxArea ;
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                for (int k = j + 1; k < points.size(); ++k) {
                    double area = triangleArea(points[i], points[j], points[k]);
    
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }

private:
    double triangleArea(vector<int>& A, vector<int>& B, vector<int>& C) {
        return 0.5 * abs(
            A[0]*(B[1]-C[1]) +
            B[0]*(C[1]-A[1]) +
            C[0]*(A[1]-B[1])
        );
    }
};


// Auto-commit update
