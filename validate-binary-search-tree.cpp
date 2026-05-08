// Problem  : Validate Binary Search Tree
// Difficulty: Medium
// Tags     : Tree, Depth-First Search, Binary Search Tree, Binary Tree
// URL      : https://leetcode.com/problems/validate-binary-search-tree/
// Solved on: 2026-04-09 00:06
// ──────────────────────────────────────────────────

class Solution {
public:
    bool helper(TreeNode* node, long minVal, long maxVal) {
        if (node == nullptr) return true;

        if (node->val <= minVal || node->val >= maxVal) {
            return false;
        }

        return helper(node->left, minVal, node->val) &&
               helper(node->right, node->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX); 
    }
};


// Auto-commit update
