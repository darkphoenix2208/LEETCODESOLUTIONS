// Problem  : Magnetic Force Between Two Balls
// Difficulty: Medium
// Tags     : Array, Binary Search, Sorting
// URL      : https://leetcode.com/problems/magnetic-force-between-two-balls/
// Solved on: 2026-04-09 00:18
// ──────────────────────────────────────────────────

class Solution {
public:
    bool canWePlace(vector<int>& stalls, int dist, int cows) {
        int n = stalls.size();
        int cntCows = 1;
        int last = stalls[0];

        for (int i = 1; i < n; i++) {
            if (stalls[i] - last >= dist) {
                cntCows++;
                last = stalls[i];
            }
            if (cntCows >= cows) return true;
        }
        return false;
    }

    int maxDistance(vector<int>& stalls, int m) {
        int n = stalls.size();
        sort(stalls.begin(), stalls.end());

        int low = 1;
        int high = stalls[n - 1] - stalls[0];

        while (low <= high) {
            int mid = (low + high) / 2;

            if (canWePlace(stalls, mid, m)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return high;  
    }
};


// Auto-commit update
