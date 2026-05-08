// Problem  : Merge Intervals
// Difficulty: Medium
// Tags     : Array, Sorting
// URL      : https://leetcode.com/problems/merge-intervals/
// Solved on: 2026-04-09 00:20
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if (intervals.empty()) return result;

        // Step 1: Sort intervals by start time
        sort(intervals.begin(), intervals.end());

        // Step 2: Initialize the first interval
        vector<int> current = intervals[0];

        // Step 3: Iterate and merge
        for (int i = 1; i < intervals.size(); i++) {
            if (current[1] >= intervals[i][0]) {
                // Overlapping intervals — merge
                current[1] = max(current[1], intervals[i][1]);
            } else {
                // No overlap — push the current and move on
                result.push_back(current);
                current = intervals[i];
            }
        }

        // Add the last interval
        result.push_back(current);
        return result;
    }
};


// Auto-commit update
