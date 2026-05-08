// Problem  : Binary Tree Maximum Path Sum
// Difficulty: Hard
// Tags     : Dynamic Programming, Tree, Depth-First Search, Binary Tree
// URL      : https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Solved on: 2026-04-09 00:16
// ──────────────────────────────────────────────────

class Solution {
public:
    int sum(TreeNode* root, int& maxi) {
        if (root == NULL) return 0;

        int l = max(0, sum(root->left, maxi));
        int r = max(0, sum(root->right, maxi));

        maxi = max(maxi, l + r + root->val); // update max path sum

        return max(l, r) + root->val; 
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        sum(root, maxi);
        return maxi;
    }
};


// Auto-commit update
