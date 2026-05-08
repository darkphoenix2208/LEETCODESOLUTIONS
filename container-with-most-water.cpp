// Problem  : Container With Most Water
// Difficulty: Medium
// Tags     : Array, Two Pointers, Greedy
// URL      : https://leetcode.com/problems/container-with-most-water/
// Solved on: 2026-04-09 00:10
// ──────────────────────────────────────────────────

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxArea = 0;

        while (left < right) {
            int h = min(height[left], height[right]);
            int w = right - left;
            maxArea = max(maxArea, h * w);

            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return maxArea;
    }
};


// Auto-commit update
