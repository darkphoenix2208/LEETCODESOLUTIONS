// Problem  : Minimum Operations to Make a Uni-Value Grid
// Difficulty: Medium
// Tags     : Array, Math, Sorting, Matrix
// URL      : https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/
// Solved on: 2026-05-08 21:47
// ──────────────────────────────────────────────────

class Solution {
public:
    int minOperations(vector<vector<int>>& g, int x) {
        vector<int> a;

        int b=g[0][0];

        for(auto &r:g){
            for(auto &v:r){
                if((v-b)%x!=0) return -1;
                a.push_back(v);
            }
        }

        sort(a.begin(),a.end());

        int n=a.size();
        int m=a[n/2];

        int ans=0;

        for(auto &v:a){
            ans+=abs(v-m)/x;
        }

        return ans;
    }
};

// Auto-commit update
