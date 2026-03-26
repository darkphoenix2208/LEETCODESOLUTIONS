// Problem  : Equal Sum Grid Partition II
// Difficulty: Hard
// Tags     : Array, Hash Table, Matrix, Enumeration, Prefix Sum
// URL      : https://leetcode.com/problems/equal-sum-grid-partition-ii/
// Solved on: 2026-05-08 21:50
// ──────────────────────────────────────────────────

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& g) {
        
        int m=g.size(),n=g[0].size();

        long long s=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                s+=g[i][j];
            }
        }

        vector<long long> r(m),c(n);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                r[i]+=g[i][j];
                c[j]+=g[i][j];
            }
        }

        vector<int> up(100001),down(100001);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                down[g[i][j]]++;
            }
        }

        long long a=0,b=s;

        for(int i=0;i<m-1;i++){

            a+=r[i];
            b-=r[i];

            for(int j=0;j<n;j++){
                up[g[i][j]]++;
                down[g[i][j]]--;
            }

            if(a==b) return true;

            long long d=abs(a-b);

            if(a>b){

                if(d<=100000 && up[d]){

                    if(i+1>=2 && n>=2) return true;

                    if(i==0){
                        if(g[0][0]==d || g[0][n-1]==d) return true;
                    }

                    if(n==1){
                        if(g[0][0]==d || g[i][0]==d) return true;
                    }
                }
            }
            else{

                if(d<=100000 && down[d]){

                    if(m-i-1>=2 && n>=2) return true;

                    if(i+1==m-1){
                        if(g[m-1][0]==d || g[m-1][n-1]==d) return true;
                    }

                    if(n==1){
                        if(g[i+1][0]==d || g[m-1][0]==d) return true;
                    }
                }
            }
        }

        vector<int> l(100001),rr(100001);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                rr[g[i][j]]++;
            }
        }

        a=0,b=s;

        for(int j=0;j<n-1;j++){

            a+=c[j];
            b-=c[j];

            for(int i=0;i<m;i++){
                l[g[i][j]]++;
                rr[g[i][j]]--;
            }

            if(a==b) return true;

            long long d=abs(a-b);

            if(a>b){

                if(d<=100000 && l[d]){

                    if(j+1>=2 && m>=2) return true;

                    if(j==0){
                        if(g[0][0]==d || g[m-1][0]==d) return true;
                    }

                    if(m==1){
                        if(g[0][0]==d || g[0][j]==d) return true;
                    }
                }
            }
            else{

                if(d<=100000 && rr[d]){

                    if(n-j-1>=2 && m>=2) return true;

                    if(j+1==n-1){
                        if(g[0][n-1]==d || g[m-1][n-1]==d) return true;
                    }

                    if(m==1){
                        if(g[0][j+1]==d || g[0][n-1]==d) return true;
                    }
                }
            }
        }

        return false;
    }
};

// Auto-commit update
