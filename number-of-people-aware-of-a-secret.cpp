// Problem  : Number of People Aware of a Secret
// Difficulty: Medium
// Tags     : Dynamic Programming, Queue, Simulation
// URL      : https://leetcode.com/problems/number-of-people-aware-of-a-secret/
// Solved on: 2026-04-09 00:13
// ──────────────────────────────────────────────────

class Solution {
public:
    const int MOD = 1e9 + 7;

    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n + 2, 0);      
        vector<long long> pref(n + 2, 0);   

        dp[1] = 1;
        pref[1] = 1;

        for (int day = 2; day <= n; day++) {
            int share_start = max(0, day - forget);
            int share_end = max(0, day - delay);

            long long to_add = (pref[share_end] - pref[share_start] + MOD) % MOD;
            dp[day] = to_add;

            pref[day] = (pref[day - 1] + dp[day]) % MOD;
        }
        long long result = 0;
        for (int day = n - forget + 1; day <= n; day++) {
            if (day >= 1) {
                result = (result + dp[day]) % MOD;
            }
        }

        return result;
    }
};


// Auto-commit update
