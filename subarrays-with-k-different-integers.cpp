// Problem  : Subarrays with K Different Integers
// Difficulty: Hard
// Tags     : Array, Hash Table, Sliding Window, Counting
// URL      : https://leetcode.com/problems/subarrays-with-k-different-integers/
// Solved on: 2026-04-08 23:56
// ──────────────────────────────────────────────────

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& v, int k) {
        map<int,int> mpp;
        int n = v.size();
        int i = 0;
        int ans = 0;
        int prefix = 0;

        for (int j = 0; j < n; j++) {
            mpp[v[j]]++;
            if (mpp.size() > k) {
                while (mpp.size() > k) {
                    mpp[v[i]]--;
                    if (mpp[v[i]] == 0) mpp.erase(v[i]);
                    i++;
                }
                prefix = 0;
            }
            if (mpp.size() == k) {
                while (mpp[v[i]] > 1) {
                    mpp[v[i]]--;
                    i++;
                    prefix++;
                }
                ans += prefix + 1;
            }
        }
        return ans;
    }
};


// Auto-commit update
