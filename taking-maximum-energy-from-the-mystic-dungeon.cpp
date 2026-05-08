// Problem  : Taking Maximum Energy From the Mystic Dungeon
// Difficulty: Medium
// Tags     : Array, Dynamic Programming, Prefix Sum
// URL      : https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/
// Solved on: 2026-04-09 00:09
// ──────────────────────────────────────────────────

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n);
        int maxEnergy = INT_MIN;

        for (int i = n - 1; i >= 0; --i) {
            if (i + k >= n) {
                dp[i] = energy[i];
            } else {
                dp[i] = energy[i] + dp[i + k];
            }
            maxEnergy = max(maxEnergy, dp[i]);
        }

        return maxEnergy;
    }
};


// Auto-commit update
