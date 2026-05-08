// Problem  : House Robber
// Difficulty: Medium
// Tags     : Array, Dynamic Programming
// URL      : https://leetcode.com/problems/house-robber/
// Solved on: 2026-04-09 00:17
// ──────────────────────────────────────────────────

class Solution {
public:
    int rob(vector<int>& arr) {
        int n=arr.size();
        int prev = arr[0];   
    int prev2 = 0;       
    
    for (int i = 1; i < n; i++) {
        int pick = arr[i];  
        if (i > 1)
            pick += prev2;  // Add the maximum sum two elements ago
        
        int nonPick = 0 + prev;  // Maximum sum if we don't pick the current element
        
        int cur_i = max(pick, nonPick);  // Maximum sum ending at the current element
        prev2 = prev;   // Update the maximum sum two elements ago
        prev = cur_i;   // Update the maximu
    }
    
    return prev;  // Return the maximum sum
    }
};

// Auto-commit update
