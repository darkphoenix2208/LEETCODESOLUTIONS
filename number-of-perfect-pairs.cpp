// Problem  : Number of Perfect Pairs
// Difficulty: Medium
// Tags     : Array, Math, Two Pointers, Sorting
// URL      : https://leetcode.com/problems/number-of-perfect-pairs/
// Solved on: 2026-04-09 00:15
// ──────────────────────────────────────────────────

#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

class Solution {
public:
    long long perfectPairs(const vector<int>& nums) {
        int n = (int)nums.size();
        vector<long long> absVals(n);

        for (int i = 0; i < n; ++i) {
            absVals[i] = llabs((long long)nums[i]);
        }

        sort(absVals.begin(), absVals.end());

        long long result = 0;
        int right = 0;

        for (int left = 0; left < n; ++left) {
            if (right < left + 1) right = left + 1;
            while (right < n && absVals[right] <= 2 * absVals[left]) {
                ++right;
            }
            result += (right - left - 1);
        }

        return result;
    }
};


// Auto-commit update
