// Problem  : Maximum Number of Distinct Elements After Operations
// Difficulty: Medium
// Tags     : Array, Greedy, Sorting
// URL      : https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/
// Solved on: 2026-04-09 00:07
// ──────────────────────────────────────────────────

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long prev = LLONG_MIN;
        int count = 0;

        for (int num : nums) {
    
            long long newVal = max((long long)num - k, prev + 1);

            if (newVal <= num + k) {
                count++;
                prev = newVal; 
            }
        }

        return count;
    }
};


// Auto-commit update
