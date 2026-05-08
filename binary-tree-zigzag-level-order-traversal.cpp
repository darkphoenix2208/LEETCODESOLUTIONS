// Problem  : Binary Tree Zigzag Level Order Traversal
// Difficulty: Medium
// Tags     : Tree, Breadth-First Search, Binary Tree
// URL      : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// Solved on: 2026-04-09 00:17
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                // insert at different position depending on direction
                int index = leftToRight ? i : size - 1 - i;
                level[index] = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(level);
            leftToRight = !leftToRight;
        }

        return result;
    }
};


// Auto-commit update
