// Problem  : Minimum Number of Days to Make m Bouquets
// Difficulty: Medium
// Tags     : Array, Binary Search
// URL      : https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
// Solved on: 2026-04-09 00:18
// ──────────────────────────────────────────────────

class Solution {
public:

    bool possible(vector<int> &arr, int day, int m, int k) {
        int cnt = 0;
        int noOfB = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= day) {
                cnt++;
                if (cnt == k) {
                    noOfB++;
                    cnt = 0;
                }
            } else {
                cnt = 0;
            }
        }
        return noOfB >= m;
    }

    int minDays(vector<int>& arr, int m, int k) {
        int n = arr.size();
        if (1LL * m * k > n) return -1;

        int low = INT_MAX, high = INT_MIN;
        for (int i = 0; i < n; i++) {
            low = min(low, arr[i]);
            high = max(high, arr[i]);
        }

        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(arr, mid, m, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};


// Auto-commit update
