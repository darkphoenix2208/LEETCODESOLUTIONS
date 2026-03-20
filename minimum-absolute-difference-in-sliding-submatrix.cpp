// Problem  : Minimum Absolute Difference in Sliding Submatrix
// Difficulty: Medium
// Tags     : Array, Sorting, Matrix
// URL      : https://leetcode.com/problems/minimum-absolute-difference-in-sliding-submatrix/
// Solved on: 2026-05-08 21:50
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& g, int k) {
        
        int m = g.size();
        int n = g[0].size();

        vector<vector<int>> a(m-k+1, vector<int>(n-k+1));

        for(int i=0;i<=m-k;i++){
            for(int j=0;j<=n-k;j++){

                vector<int> v;

                for(int x=i;x<i+k;x++){
                    for(int y=j;y<j+k;y++){
                        v.push_back(g[x][y]);
                    }
                }

                sort(v.begin(), v.end());

                v.erase(unique(v.begin(), v.end()), v.end());

                if(v.size()==1){
                    a[i][j]=0;
                    continue;
                }

                int mn=1e9;

                for(int t=1;t<v.size();t++){
                    mn=min(mn, v[t]-v[t-1]);
                }

                a[i][j]=mn;
            }
        }

        return a;
    }
};

// Auto-commit update
