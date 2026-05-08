// Problem  : Koko Eating Bananas
// Difficulty: Medium
// Tags     : Array, Binary Search
// URL      : https://leetcode.com/problems/koko-eating-bananas/
// Solved on: 2026-04-09 00:18
// ──────────────────────────────────────────────────

#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long eating(vector<int>& piles, int mid) {
        long long totalTime = 0;
        for (int i = 0; i < piles.size(); i++) {
            // avoid floating point: do ceil manually using integer math
            totalTime += (piles[i] + mid - 1) / mid;
        }
        return totalTime;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalH = eating(piles, mid);

            if (totalH <= h) {
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
