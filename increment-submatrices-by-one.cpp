// Problem  : Increment Submatrices by One
// Difficulty: Medium
// Tags     : Array, Matrix, Prefix Sum
// URL      : https://leetcode.com/problems/increment-submatrices-by-one/
// Solved on: 2026-04-09 00:04
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>  arr(n+1, vector<int>(n, 0));
        for(auto& q: queries){
            const int r1=q[0], c1=q[1], r2=q[2], c2=q[3];
            arr[r1][c1]++;
            arr[r2+1][c1]--;
            if (c2+1<n){
                arr[r1][c2+1]--;
                arr[r2+1][c2+1]++;
            }
        }
        for(int j=1; j<n; j++)
            arr[0][j]+=arr[0][j-1];
        for(int i=1; i<n; i++){
            arr[i][0]+=arr[i-1][0];
            for(int j=1; j<n; j++){
                arr[i][j]+=arr[i][j-1]+arr[i-1][j]-arr[i-1][j-1];
            }
        }
        arr.resize(n);
        return arr;
    }
};

// Auto-commit update
