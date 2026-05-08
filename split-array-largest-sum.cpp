// Problem  : Split Array Largest Sum
// Difficulty: Hard
// Tags     : Array, Binary Search, Dynamic Programming, Greedy, Prefix Sum
// URL      : https://leetcode.com/problems/split-array-largest-sum/
// Solved on: 2026-04-09 00:18
// ──────────────────────────────────────────────────

class Solution {
public:
    int subarray(vector<int>& nums, int maxSumAllowed) {
        int subarrays = 1;  // start with one subarray
        int currentSum = 0;

        for (int num : nums) {
            if (currentSum + num > maxSumAllowed) {
                subarrays++;
                currentSum = num;  // start new subarray
            } else {
                currentSum += num;
            }
        }
        return subarrays;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0); 
        int ans = high;

        while (low <= high) {
            int mid = (low + high) / 2;
            int call = subarray(nums, mid);

            if (call <= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans; // ✅ This was missing
    }
};


// Auto-commit update
