// Problem  : Find the Number of Ways to Place People II
// Difficulty: Hard
// Tags     : Array, Math, Geometry, Sorting, Enumeration
// URL      : https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/
// Solved on: 2026-04-09 00:13
// ──────────────────────────────────────────────────

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int count = 0;

    
        sort(points.begin(), points.end(), [](auto &a, auto &b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] > b[0];
        });

        for (int i = 0; i < n; i++) {
            int minY = INT_MAX;
            for (int j = i + 1; j < n; j++) {
                if (points[j][1] >= points[i][1]) {
                    if (points[j][1] < minY) {
                        count++;
                        minY = points[j][1];
                    }
                }
            }
        }

        return count;
    }
};


// Auto-commit update
