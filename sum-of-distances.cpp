// Problem  : Sum of Distances
// Difficulty: Medium
// Tags     : Array, Hash Table, Prefix Sum
// URL      : https://leetcode.com/problems/sum-of-distances/
// Solved on: 2026-05-08 21:47
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<long long> distance(vector<int>& a) {
        int n = a.size();
        vector<long long> ans(n,0);

        unordered_map<int, vector<int>> mp;

        for(int i=0;i<n;i++) mp[a[i]].push_back(i);

        for(auto &p:mp){
            vector<int> &v = p.second;
            int m = v.size();

            vector<long long> pre(m,0);
            pre[0] = v[0];
            for(int i=1;i<m;i++) pre[i] = pre[i-1] + v[i];

            for(int i=0;i<m;i++){
                int idx = v[i];

                long long l = (long long)i * idx - (i>0 ? pre[i-1] : 0);
                long long r = (pre[m-1] - pre[i]) - (long long)(m-i-1)*idx;

                ans[idx] = l + r;
            }
        }

        return ans;
    }
};

// Auto-commit update
