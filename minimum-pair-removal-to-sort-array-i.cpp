// Problem  : Minimum Pair Removal to Sort Array I
// Difficulty: Easy
// Tags     : Array, Hash Table, Linked List, Heap (Priority Queue), Simulation, Doubly-Linked List, Ordered Set
// URL      : https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/
// Solved on: 2026-04-08 23:57
// ──────────────────────────────────────────────────

class Solution {
private:
    bool isSorted(vector<int>& nums, int n) {
        for(int i = 1; i < n; i++) {
            if(nums[i] < nums[i - 1]) return false;
        }
        return true;
    }
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0, n = nums.size();
        while(!isSorted(nums, n)) {
            ans += 1;
            int min_sum = INT_MAX, pos = -1;
            for(int i = 1; i < n; i++) {
                int sum = nums[i - 1] + nums[i];
                if(sum < min_sum) {
                    min_sum = sum;
                    pos = i;
                }
            }
            nums[pos - 1] = min_sum;
            for(int i = pos; i < n - 1; i++) nums[i] = nums[i + 1];
            n--;
        }
        return ans;
    }
};

// Auto-commit update
