// Problem  : Non-overlapping Intervals
// Difficulty: Medium
// Tags     : Array, Dynamic Programming, Greedy, Sorting
// URL      : https://leetcode.com/problems/non-overlapping-intervals/
// Solved on: 2026-04-09 00:21
// ──────────────────────────────────────────────────

class Solution {
public:
    // Comparator to sort intervals by their end time
    static bool comparator(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), comparator);

        int count = 1; // Count of non-overlapping intervals
        int last_end = intervals[0][1];

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= last_end) {
                count++;
                last_end = intervals[i][1];
            }
        }

        // Total - non-overlapping = minimum removals
        return n - count;
    }
};


// Auto-commit update
