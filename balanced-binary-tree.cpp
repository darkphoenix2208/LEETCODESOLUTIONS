// Problem  : Balanced Binary Tree
// Difficulty: Easy
// Tags     : Tree, Depth-First Search, Binary Tree
// URL      : https://leetcode.com/problems/balanced-binary-tree/
// Solved on: 2026-04-09 00:16
// ──────────────────────────────────────────────────

class Solution {
public:
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int l = height(root->left);
        int r = height(root->right);
        return 1 + max(l, r);
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        int l = height(root->left);
        int r = height(root->right);

        // Recursively check if left and right subtrees are also balanced
        if (abs(l - r) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
            return true;
        }

        return false;
    }
};


// Auto-commit update
