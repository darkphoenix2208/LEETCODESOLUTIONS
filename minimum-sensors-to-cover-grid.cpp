// Problem  : Minimum Sensors to Cover Grid
// Difficulty: Medium
// Tags     : Math
// URL      : https://leetcode.com/problems/minimum-sensors-to-cover-grid/
// Solved on: 2026-04-09 00:15
// ──────────────────────────────────────────────────

class Solution {
public:
    int minSensors(int n, int m, int k) {
        int s = 2 * k + 1;  

        int rows = (n + s - 1) / s;
        int cols = (m + s - 1) / s;

        return rows * cols; 
    }
};


// Auto-commit update
