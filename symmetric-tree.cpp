// Problem  : Symmetric Tree
// Difficulty: Easy
// Tags     : Tree, Depth-First Search, Breadth-First Search, Binary Tree
// URL      : https://leetcode.com/problems/symmetric-tree/
// Solved on: 2026-04-09 00:16
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
        bool s(TreeNode* root1,TreeNode* root2){
            if(root1==NULL || root2==NULL){
                return root1==root2;
            }
            return (root1->val ==root2->val) && s(root1->left,root2->right) && s(root1->right,root2->left);
        }
    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        }
        return s(root->left,root->right);
    }
};

// Auto-commit update
