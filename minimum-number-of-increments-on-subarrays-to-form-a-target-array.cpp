// Problem  : Minimum Number of Increments on Subarrays to Form a Target Array
// Difficulty: Hard
// Tags     : Array, Dynamic Programming, Stack, Greedy, Monotonic Stack
// URL      : https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/
// Solved on: 2026-04-09 00:06
// ──────────────────────────────────────────────────

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n=target.size(), ans=target[0];
        for(int i=1; i<n; i++){
            ans+=max(target[i]-target[i-1], 0);
        }
        return ans;
    }
};

// Auto-commit update
