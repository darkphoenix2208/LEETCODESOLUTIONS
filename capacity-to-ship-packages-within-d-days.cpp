// Problem  : Capacity To Ship Packages Within D Days
// Difficulty: Medium
// Tags     : Array, Binary Search
// URL      : https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
// Solved on: 2026-04-09 00:18
// ──────────────────────────────────────────────────

class Solution {
public:
    int findDays(vector<int>& weights, int cap) {
        int days = 1; 
        int load = 0;
        int n = weights.size();
        for (int i = 0; i < n; i++) {
            if (load + weights[i] > cap) {
                days += 1; 
                load = weights[i]; 
            } else {
                load += weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int high = std::accumulate(weights.begin(), weights.end(), 0);
        int low = *max_element(weights.begin(), weights.end());
        int mid;

        while (low <= high) {
            mid = (low + high) / 2;
            int a = findDays(weights, mid); 

            if (a <= days) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};


// Auto-commit update
