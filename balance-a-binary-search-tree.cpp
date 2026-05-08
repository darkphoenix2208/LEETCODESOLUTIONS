// Problem  : Balance a Binary Search Tree
// Difficulty: Medium
// Tags     : Divide and Conquer, Greedy, Tree, Depth-First Search, Binary Search Tree, Binary Tree
// URL      : https://leetcode.com/problems/balance-a-binary-search-tree/
// Solved on: 2026-04-08 23:53
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
private:
    vector<int> nums;
public:
    TreeNode* balanceBST(TreeNode* root) {
        nums.clear();
        getNumbers(root);
        return balanceTree(0, nums.size() - 1);
    }
private:
    void getNumbers(TreeNode* node) {
        if (node == nullptr) return;
        getNumbers(node->left);
        nums.push_back(node->val);
        getNumbers(node->right);
    }
    TreeNode* balanceTree(int l, int r) {
        if (l > r) return nullptr;
        int middleIdx = l + (r - l) / 2;
        TreeNode* root = new TreeNode(nums[middleIdx]);
        root->left = balanceTree(l, middleIdx - 1);
        root->right = balanceTree(middleIdx + 1, r);
        return root;
    }
};

// Auto-commit update
