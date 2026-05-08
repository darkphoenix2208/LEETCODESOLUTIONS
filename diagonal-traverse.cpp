// Problem  : Diagonal Traverse
// Difficulty: Medium
// Tags     : Array, Matrix, Simulation
// URL      : https://leetcode.com/problems/diagonal-traverse/
// Solved on: 2026-04-09 00:15
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> ans;
        ans.reserve(n * m);

        for (int d = 0; d < n + m - 1; d++) {
            vector<int> temp;

            
            for (int i = 0; i < n; i++) {
                int j = d - i;
                if (j >= 0 && j < m) {
                    temp.push_back(mat[i][j]);
                }
            }

        
            if (d % 2 == 0) {
                reverse(temp.begin(), temp.end());
            }

    
            ans.insert(ans.end(), temp.begin(), temp.end());
        }
        return ans;
    }
};


// Auto-commit update
