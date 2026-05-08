// Problem  : Number of Zero-Filled Subarrays
// Difficulty: Medium
// Tags     : Array, Math
// URL      : https://leetcode.com/problems/number-of-zero-filled-subarrays/
// Solved on: 2026-04-09 00:15
// ──────────────────────────────────────────────────

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& v) {
        long long count = 0;
        long long ans=0;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            if (v[i] == 0) {
                count++;
                
            }
            else{
                ans+=count*(count+1)/2;
                count=0;
            }
        }
        ans+=count*(count+1)/2;
        return ans;
    }
};


// Auto-commit update
