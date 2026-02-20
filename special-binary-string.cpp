// Problem  : Special Binary String
// Difficulty: Hard
// Tags     : String, Divide and Conquer, Sorting
// URL      : https://leetcode.com/problems/special-binary-string/
// Solved on: 2026-05-08 21:52
// ──────────────────────────────────────────────────

class Solution {
public:
    string makeLargestSpecial(string s) {
        if (s == "") return s;
        vector<string> ans;
        int cnt = 0;
        for (int i = 0, j = 0; i < s.size(); ++i) {
            cnt += s[i] == '1' ? 1 : -1;
            if (cnt == 0) {
                ans.push_back("1" + makeLargestSpecial(s.substr(j + 1, i - j - 1)) + "0");
                j = i + 1;
            }
        }
        sort(ans.begin(), ans.end(), greater<string>{});
        return accumulate(ans.begin(), ans.end(), ""s);
    }
};

// Auto-commit update
