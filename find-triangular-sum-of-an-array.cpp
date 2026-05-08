// Problem  : Find Triangular Sum of an Array
// Difficulty: Medium
// Tags     : Array, Math, Simulation, Combinatorics, Number Theory
// URL      : https://leetcode.com/problems/find-triangular-sum-of-an-array/
// Solved on: 2026-04-09 00:10
// ──────────────────────────────────────────────────

#include <vector>
using namespace std;

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while (nums.size() > 1) {
            vector<int> newNums;
            for (int i = 0; i < nums.size() - 1; ++i) {
                newNums.push_back((nums[i] + nums[i + 1]) % 10);
            }
            nums = newNums;
        }
        return nums[0];
    }
};


// Auto-commit update
