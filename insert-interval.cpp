// Problem  : Insert Interval
// Difficulty: Medium
// Tags     : Array
// URL      : https://leetcode.com/problems/insert-interval/
// Solved on: 2026-04-09 00:20
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0;
        int n = intervals.size();

        // Step 1: Add intervals before newInterval (no overlap)
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }

        // Step 2: Merge overlapping intervals with newInterval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.push_back(newInterval);

        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};


// Auto-commit update
