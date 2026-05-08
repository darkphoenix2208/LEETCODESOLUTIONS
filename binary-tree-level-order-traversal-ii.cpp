// Problem  : Binary Tree Level Order Traversal II
// Difficulty: Medium
// Tags     : Tree, Breadth-First Search, Binary Tree
// URL      : https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
// Solved on: 2026-04-09 00:08
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> level;
            level.reserve(n);
            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front(); q.pop();
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.emplace_back(move(level));
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// Auto-commit update
