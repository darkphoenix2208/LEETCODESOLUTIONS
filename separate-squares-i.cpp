// Problem  : Separate Squares I
// Difficulty: Medium
// Tags     : Array, Binary Search
// URL      : https://leetcode.com/problems/separate-squares-i/
// Solved on: 2026-04-08 23:58
// ──────────────────────────────────────────────────

class Solution {
public:
    double f(double mid, vector<vector<int>>& v) {
        double a = 0.0;
        double b = 0.0;

        for (int i = 0; i < v.size(); i++) {
            double y = v[i][1];
            double l = v[i][2];
            double area = l * l;

            if (y >= mid) {
                a += area;
            }
            else if (y + l <= mid) {
                b += area;
            }
            else {
                double below = l * (mid - y);
                b += below;
                a += area - below;
            }
        }

        return a - b;  
    }

    double separateSquares(vector<vector<int>>& v) {
        double l = 1e18, h = -1e18;

        for (int i = 0; i < v.size(); i++) {
            l = min(l, (double)v[i][1]);
            h = max(h, (double)(v[i][1] + v[i][2]));
        }

        for (int i = 0; i < 100; i++) {   
            double mid = l + (h - l) / 2.0;
            double diff = f(mid, v);

            if (diff > 0) {
                l = mid;
            } else {
                h = mid;
            }
        }

        return l;
    }
};


// Auto-commit update
