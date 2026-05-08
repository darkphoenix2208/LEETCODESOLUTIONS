// Problem  : Binary Tree Level Order Traversal
// Difficulty: Medium
// Tags     : Tree, Breadth-First Search, Binary Tree
// URL      : https://leetcode.com/problems/binary-tree-level-order-traversal/
// Solved on: 2026-04-09 00:21
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;  // ✅ fix null

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {  // ✅ fix condition
            int levelSize = q.size();   // number of nodes at this level
            vector<int> level;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            ans.push_back(level);
        }

        return ans;
    }
};


// Auto-commit update
