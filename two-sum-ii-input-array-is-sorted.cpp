// Problem  : Two Sum II - Input Array Is Sorted
// Difficulty: Medium
// Tags     : Array, Two Pointers, Binary Search
// URL      : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Solved on: 2026-04-09 00:16
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0;
        int high = numbers.size() - 1;

        while (low < high) {  // low < high, not <=
            int total = numbers[low] + numbers[high];

            if (total == target) {
                // +1 because problem wants 1-based indexing
                return {low + 1, high + 1};
            }
            else if (total < target) {
                low++;   
            }
            else {
                high--;  
            }
        }

        return {}; 
    }
};


// Auto-commit update
