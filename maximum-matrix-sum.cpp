// Problem  : Maximum Matrix Sum
// Difficulty: Medium
// Tags     : Array, Greedy, Matrix
// URL      : https://leetcode.com/problems/maximum-matrix-sum/
// Solved on: 2026-04-09 00:00
// ──────────────────────────────────────────────────

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& m) {
        int o=0,e=0;
        long long sum=0;
        int a=INT_MAX;
        int n=m.size();

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(m[i][j]>=0){
                    o++;
                }
                else{
                    e++;
                }
                sum+=abs(m[i][j]);
                a=min(a,abs(m[i][j]));
            }
        }
        if(e&1){
            return sum-2*a;
        }
        else{
           return sum; 
        }
    }
};

// Auto-commit update
