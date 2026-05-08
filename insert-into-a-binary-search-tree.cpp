// Problem  : Insert into a Binary Search Tree
// Difficulty: Medium
// Tags     : Tree, Binary Search Tree, Binary Tree
// URL      : https://leetcode.com/problems/insert-into-a-binary-search-tree/
// Solved on: 2026-04-09 00:06
// ──────────────────────────────────────────────────

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }

        if (val > root->val) {
            if (root->right == nullptr) {
                root->right = new TreeNode(val);
            } else {
                insertIntoBST(root->right, val); 
            }
        } else {
            if (root->left == nullptr) {
                root->left = new TreeNode(val); 
            } else {
                insertIntoBST(root->left, val); 
            }
        }
        return root;
    }
};


// Auto-commit update
