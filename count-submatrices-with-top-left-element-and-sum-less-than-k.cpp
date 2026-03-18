// Problem  : Count Submatrices with Top-Left Element and Sum Less Than k
// Difficulty: Medium
// Tags     : Array, Matrix, Prefix Sum
// URL      : https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/
// Solved on: 2026-05-08 21:50
// ──────────────────────────────────────────────────

class Solution {
public:
int countSubmatrices(vector<vector<int>>& grid, int k) {

int m=grid.size();
int n=grid[0].size();

vector<vector<long long>> pref(m,vector<long long>(n,0));

int ans=0;

for(int i=0;i<m;i++){
for(int j=0;j<n;j++){

pref[i][j]=grid[i][j];

if(i>0) pref[i][j]+=pref[i-1][j];
if(j>0) pref[i][j]+=pref[i][j-1];
if(i>0 && j>0) pref[i][j]-=pref[i-1][j-1];

if(pref[i][j]<=k) ans++;
}
}

return ans;
}
};

// Auto-commit update
