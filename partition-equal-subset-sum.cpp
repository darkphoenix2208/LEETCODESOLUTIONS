// Problem  : Partition Equal Subset Sum
// Difficulty: Medium
// Tags     : Array, Dynamic Programming
// URL      : https://leetcode.com/problems/partition-equal-subset-sum/
// Solved on: 2026-04-09 00:16
// ──────────────────────────────────────────────────

class Solution {
public:
    bool subsetSumToK(int n, int k, vector<int> &arr) {
        vector<bool> prev(k + 1, false);
        prev[0] = true;

        if (arr[0] <= k) {
            prev[arr[0]] = true;
        }

        for (int ind = 1; ind < n; ind++) {
            vector<bool> cur(k + 1, false);
            cur[0] = true;

            for (int target = 1; target <= k; target++) {
                bool notTaken = prev[target];
                bool taken = false;
                if (arr[ind] <= target) {
                    taken = prev[target - arr[ind]];
                }
                cur[target] = notTaken || taken;
            }
            prev = cur;
        }

        return prev[k];
    }

    bool canPartition(vector<int>& vec) {
        int sum = std::accumulate(vec.begin(), vec.end(), 0);
        if (sum % 2 != 0) return false; // Can't partition if sum is odd
        return subsetSumToK(vec.size(), sum / 2, vec); // ← Added return & semicolon
    }
};


// Auto-commit update
