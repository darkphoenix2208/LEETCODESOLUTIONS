// Problem  : Closest Equal Element Queries
// Difficulty: Medium
// Tags     : Array, Hash Table, Binary Search
// URL      : https://leetcode.com/problems/closest-equal-element-queries/
// Solved on: 2026-05-08 21:48
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        for(int idx : queries) {
            auto &v = mp[nums[idx]];

            if(v.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            int pos = lower_bound(v.begin(), v.end(), idx) - v.begin();
            int res = INT_MAX;

            if(pos > 0) {
                int j = v[pos - 1];
                int d = abs(idx - j);
                res = min(res, min(d, n - d));
            }

            if(pos + 1 < v.size()) {
                int j = v[pos + 1];
                int d = abs(idx - j);
                res = min(res, min(d, n - d));
            }

            if(pos == 0) {
                int j = v.back();
                int d = abs(idx - j);
                res = min(res, min(d, n - d));
            }

            if(pos == v.size() - 1) {
                int j = v[0];
                int d = abs(idx - j);
                res = min(res, min(d, n - d));
            }

            ans.push_back(res);
        }

        return ans;
    }
};

// Auto-commit update
