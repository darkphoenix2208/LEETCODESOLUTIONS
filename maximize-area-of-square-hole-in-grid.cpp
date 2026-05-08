// Problem  : Maximize Area of Square Hole in Grid
// Difficulty: Medium
// Tags     : Array, Sorting
// URL      : https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/
// Solved on: 2026-04-08 23:57
// ──────────────────────────────────────────────────

class Solution {
public:
int longestRun(vector<int>& bars) {
    int best = 1, cur = 1;
    for (int i = 1; i < bars.size(); i++) {
        if (bars[i] == bars[i-1] + 1)
            cur++;
        else
            cur = 1;
        best = max(best, cur);
    }
    return best + 1;
}
    int maximizeSquareHoleArea(int n, int m, vector<int>& h, vector<int>& v) {
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
     
       int maxH = longestRun(h);
int maxV = longestRun(v);
return min(maxH, maxV) * min(maxH, maxV);

    }
};

// Auto-commit update
