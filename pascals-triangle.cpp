// Problem  : Pascal's Triangle
// Difficulty: Easy
// Tags     : Array, Dynamic Programming
// URL      : https://leetcode.com/problems/pascals-triangle/
// Solved on: 2026-04-09 00:20
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> generateRow(int row) {
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1);
        for (int col = 1; col < row; col++) {
            ans = ans * (row - col);
            ans = ans / col;
            ansRow.push_back(ans);
        }
        return ansRow;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int row = 1; row <= numRows; row++) {
            ans.push_back(generateRow(row));
        }
        return ans;
    }
};


// Auto-commit update
