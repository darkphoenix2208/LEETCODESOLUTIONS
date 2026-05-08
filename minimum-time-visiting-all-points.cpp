// Problem  : Minimum Time Visiting All Points
// Difficulty: Easy
// Tags     : Array, Math, Geometry
// URL      : https://leetcode.com/problems/minimum-time-visiting-all-points/
// Solved on: 2026-04-08 23:58
// ──────────────────────────────────────────────────

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& v) {
        int n=v.size();
        int ans=0;
        for(int i=0;i<n-1;i++){
            int a=abs(v[i+1][1]-v[i][1]);
            int b=abs(v[i+1][0]-v[i][0]);
            int c=min(a,b);
            int d=max(a,b)-min(a,b);
            ans+=d+c;
        }
        return ans;
    }
};

// Auto-commit update
