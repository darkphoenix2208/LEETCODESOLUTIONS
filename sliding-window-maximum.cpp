// Problem  : Sliding Window Maximum
// Difficulty: Hard
// Tags     : Array, Queue, Sliding Window, Heap (Priority Queue), Monotonic Queue
// URL      : https://leetcode.com/problems/sliding-window-maximum/
// Solved on: 2026-04-09 00:20
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq; // stores indices

        for (int i = 0; i < nums.size(); i++) {
            // Remove indices outside the current window
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();

            // Remove indices whose values are less than current element
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            dq.push_back(i);

            // Add the current max to the result
            if (i >= k - 1)
                result.push_back(nums[dq.front()]);
        }

        return result;
    }
};


// Auto-commit update
