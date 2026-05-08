// Problem  : Min Cost Climbing Stairs
// Difficulty: Easy
// Tags     : Array, Dynamic Programming
// URL      : https://leetcode.com/problems/min-cost-climbing-stairs/
// Solved on: 2026-04-08 23:59
// ──────────────────────────────────────────────────

class Solution {
public:
    int f(vector<int>& dp, int i, vector<int>& cost) {
        if (i == 0) return cost[0];
        if (i == 1) return cost[1];
        if (dp[i] != -1) return dp[i];

        return dp[i] = min(f(dp, i-1, cost), f(dp, i-2, cost)) + cost[i];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);

        return min(f(dp, n-1, cost), f(dp, n-2, cost));
    }
};


// Auto-commit update
