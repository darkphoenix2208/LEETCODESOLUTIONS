// Problem  : Minimum Swaps to Arrange a Binary Grid
// Difficulty: Medium
// Tags     : Array, Greedy, Matrix
// URL      : https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/
// Solved on: 2026-05-08 21:51
// ──────────────────────────────────────────────────

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> trailing(n);
        
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = n - 1; j >= 0; j--) {
                if(grid[i][j] == 0) count++;
                else break;
            }
            trailing[i] = count;
        }
        
        int swaps = 0;
        
        for(int i = 0; i < n; i++) {
            int required = n - 1 - i;
            int j = i;
            
            while(j < n && trailing[j] < required) {
                j++;
            }
            
            if(j == n) return -1;
            
            while(j > i) {
                swap(trailing[j], trailing[j - 1]);
                swaps++;
                j--;
            }
        }
        
        return swaps;
    }
};

// Auto-commit update
