// Problem  : Binary Tree Right Side View
// Difficulty: Medium
// Tags     : Tree, Depth-First Search, Breadth-First Search, Binary Tree
// URL      : https://leetcode.com/problems/binary-tree-right-side-view/
// Solved on: 2026-04-09 00:16
// ──────────────────────────────────────────────────

class Solution {
public:
    void dfs(TreeNode* root, int level, vector<int>& vec) {
        if (root == NULL) return;

        // If we're visiting this level for the first time
        if (level == vec.size()) {
            vec.push_back(root->val);
        }

        // First go to the right (because we want rightmost nodes)
        dfs(root->right, level + 1, vec);
        dfs(root->left, level + 1, vec);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> vec;
        dfs(root, 0, vec);  // Start from level 0
        return vec;
    }
};


// Auto-commit update
