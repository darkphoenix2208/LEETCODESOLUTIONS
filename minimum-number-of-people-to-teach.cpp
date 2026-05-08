// Problem  : Minimum Number of People to Teach
// Difficulty: Medium
// Tags     : Array, Hash Table, Greedy
// URL      : https://leetcode.com/problems/minimum-number-of-people-to-teach/
// Solved on: 2026-04-09 00:13
// ──────────────────────────────────────────────────

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<unordered_set<int>> knows(m + 1);
        for (int i = 0; i < m; i++) {
            for (int lang : languages[i]) {
                knows[i + 1].insert(lang);
            }
        }

        unordered_set<int> problematic;
        for (auto &f : friendships) {
            int u = f[0], v = f[1];
            bool canTalk = false;
            for (int lang : knows[u]) {
                if (knows[v].count(lang)) {
                    canTalk = true;
                    break;
                }
            }
            if (!canTalk) { 
                problematic.insert(u);
                problematic.insert(v);
            }
        }

        if (problematic.empty()) return 0;

        int ans = INT_MAX;
        for (int lang = 1; lang <= n; lang++) {
            int teach = 0;
            for (int user : problematic) {
                if (!knows[user].count(lang)) {
                    teach++;
                }
            }
            ans = min(ans, teach);
        }

        return ans;
    }
};


// Auto-commit update
