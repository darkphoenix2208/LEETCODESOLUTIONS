// Problem  : Same Tree
// Difficulty: Easy
// Tags     : Tree, Depth-First Search, Breadth-First Search, Binary Tree
// URL      : https://leetcode.com/problems/same-tree/
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
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL || q==NULL){
            return (p==q);

        }
      return ((p->val == q->val)
    && isSameTree(p->left, q->left)
    && isSameTree(p->right, q->right));

    }
};

// Auto-commit update
