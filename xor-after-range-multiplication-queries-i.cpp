// Problem  : XOR After Range Multiplication Queries I
// Difficulty: Medium
// Tags     : Array, Divide and Conquer, Simulation
// URL      : https://leetcode.com/problems/xor-after-range-multiplication-queries-i/
// Solved on: 2026-05-08 21:49
// ──────────────────────────────────────────────────

class Solution {
public:
int xorAfterQueries(vector<int>& a, vector<vector<int>>& q) {
long long mod=1e9+7;

for(auto &x:q){
int l=x[0],r=x[1],k=x[2],v=x[3];

for(int i=l;i<=r;i+=k){
a[i]=(1LL*a[i]*v)%mod;
}
}

int ans=0;

for(int x:a) ans^=x;

return ans;
}
};

// Auto-commit update
