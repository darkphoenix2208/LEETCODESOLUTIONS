// Problem  : Median of Two Sorted Arrays
// Difficulty: Hard
// Tags     : Array, Binary Search, Divide and Conquer
// URL      : https://leetcode.com/problems/median-of-two-sorted-arrays/
// Solved on: 2026-04-09 00:18
// ──────────────────────────────────────────────────

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Combine arrays
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());

        // Sort the combined array
        std::sort(nums1.begin(), nums1.end());

        int size = nums1.size();
        double ans;

        if (size % 2 == 0) {
            ans = (nums1[size / 2] + nums1[(size / 2) - 1]) / 2.0; // use 2.0 for float division
        } else {
            ans = nums1[size / 2];
        }

        return ans;
    }
};


// Auto-commit update
