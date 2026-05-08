// Problem  : Maximum Level Sum of a Binary Tree
// Difficulty: Medium
// Tags     : Tree, Depth-First Search, Breadth-First Search, Binary Tree
// URL      : https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
// Solved on: 2026-04-09 00:00
// ──────────────────────────────────────────────────

class Solution {
public:
    void levelOrderRec(TreeNode* root, int level, vector<vector<int>>& res) {
        if (root == nullptr) return;

        if (res.size() == level)
            res.push_back({});

        res[level].push_back(root->val);

        levelOrderRec(root->left, level + 1, res);
        levelOrderRec(root->right, level + 1, res);
    }

    int maxLevelSum(TreeNode* root) {
        vector<vector<int>> res;
        levelOrderRec(root, 0, res);

        int ans = INT_MIN;
int r=0;
        for (int i = 0; i < res.size(); i++) {
            int sum = 0;
            for (int j = 0; j < res[i].size(); j++) {
                sum += res[i][j];
            }
          if(sum>ans){
            ans=max(sum,ans);
            r=i+1;
          }
        }

        return r;
    }
};


// Auto-commit update
