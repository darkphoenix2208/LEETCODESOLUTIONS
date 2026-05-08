// Problem  : Lexicographically Smallest String After Applying Operations
// Difficulty: Medium
// Tags     : String, Depth-First Search, Breadth-First Search, Enumeration
// URL      : https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/
// Solved on: 2026-04-09 00:07
// ──────────────────────────────────────────────────

class Solution {
public:
    string addOperation(string s, int a, bool oddOnly) {
        for (int i = (oddOnly ? 1 : 0); i < s.size(); i += 2)
            s[i] = (s[i] - '0' + a) % 10 + '0';
        return s;
    }

    string rotateRight(string s, int b) {
        int n = s.size();
        b %= n;
        return s.substr(n - b) + s.substr(0, n - b);
    }

    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        unordered_set<string> vis;
        string ans = s;
        
        q.push(s);
        vis.insert(s);

        while (!q.empty()) {
            string cur = q.front();
            q.pop();

            ans = min(ans, cur);

        
            string t1 = addOperation(cur, a, true);
            if (!vis.count(t1)) {
                vis.insert(t1);
                q.push(t1);
            }

            
            string t2 = rotateRight(cur, b);
            if (!vis.count(t2)) {
                vis.insert(t2);
                q.push(t2);
            }
        }
        return ans;
    }
};

// Auto-commit update
