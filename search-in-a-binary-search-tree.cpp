// Problem  : Search in a Binary Search Tree
// Difficulty: Easy
// Tags     : Tree, Binary Search Tree, Binary Tree
// URL      : https://leetcode.com/problems/search-in-a-binary-search-tree/
// Solved on: 2026-04-09 00:21
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
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root!=nullptr && root->val!= val){
            root=val<root->val? root->left : root->right;
        }
        return root;
    }
};

// Auto-commit update
