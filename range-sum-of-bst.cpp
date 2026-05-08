// Problem  : Range Sum of BST
// Difficulty: Easy
// Tags     : Tree, Depth-First Search, Binary Search Tree, Binary Tree
// URL      : https://leetcode.com/problems/range-sum-of-bst/
// Solved on: 2026-04-09 00:09
// ──────────────────────────────────────────────────

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr)
            return 0;

        if (root->val >= low && root->val <= high) {
            return root->val + 
                   rangeSumBST(root->left, low, high) + 
                   rangeSumBST(root->right, low, high);
        }

        else if (root->val < low) {
            return rangeSumBST(root->right, low, high);
        }
        else {
            return rangeSumBST(root->left, low, high);
        }
    }
};


// Auto-commit update
