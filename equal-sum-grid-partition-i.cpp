// Problem  : Equal Sum Grid Partition I
// Difficulty: Medium
// Tags     : Array, Matrix, Enumeration, Prefix Sum
// URL      : https://leetcode.com/problems/equal-sum-grid-partition-i/
// Solved on: 2026-05-08 21:50
// ──────────────────────────────────────────────────

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& g) {
        
        int n=g.size(),m=g[0].size();

        long long s=0;

        vector<long long> r(n,0), c(m,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                s+=g[i][j];
                r[i]+=g[i][j];
                c[j]+=g[i][j];
            }
        }

        if(s%2) return false;

        long long x=0;

        for(int i=0;i<n-1;i++){
            x+=r[i];
            if(x==s-x) return true;
        }

        x=0;

        for(int j=0;j<m-1;j++){
            x+=c[j];
            if(x==s-x) return true;
        }

        return false;
    }
};

// Auto-commit update
