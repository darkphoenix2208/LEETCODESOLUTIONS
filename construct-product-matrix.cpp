// Problem  : Construct Product Matrix
// Difficulty: Medium
// Tags     : Array, Matrix, Prefix Sum
// URL      : https://leetcode.com/problems/construct-product-matrix/
// Solved on: 2026-05-08 21:50
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& g) {
        
        int n=g.size(),m=g[0].size();
        int k=n*m;
        int mod=12345;

        vector<long long> a;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                a.push_back(g[i][j]%mod);
            }
        }

        vector<long long> p(k,1),s(k,1);

        for(int i=1;i<k;i++){
            p[i]=(p[i-1]*a[i-1])%mod;
        }

        for(int i=k-2;i>=0;i--){
            s[i]=(s[i+1]*a[i+1])%mod;
        }

        vector<vector<int>> r(n,vector<int>(m));

        for(int i=0;i<k;i++){
            int x=i/m;
            int y=i%m;
            r[x][y]=(p[i]*s[i])%mod;
        }

        return r;
    }
};

// Auto-commit update
