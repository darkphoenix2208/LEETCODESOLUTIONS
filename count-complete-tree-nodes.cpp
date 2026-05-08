// Problem  : Count Complete Tree Nodes
// Difficulty: Easy
// Tags     : Binary Search, Bit Manipulation, Tree, Binary Tree
// URL      : https://leetcode.com/problems/count-complete-tree-nodes/
// Solved on: 2026-04-09 00:16
// ──────────────────────────────────────────────────

class Solution {
public:
    int findl(TreeNode* node) {
        int h = 0;
        while (node) {
            h++;
            node = node->left;
        }
        return h;
    }

    int findr(TreeNode* node) {
        int h = 0;
        while (node) {
            h++;
            node = node->right;
        }
        return h;
    }

    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;

        int l = findl(root);
        int r = findr(root);

        if (l == r) {
            // If it's a perfect binary tree
            return (1 << l) - 1;
        }

    
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};


// Auto-commit update
