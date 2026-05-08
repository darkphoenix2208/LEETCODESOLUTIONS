// Problem  : Process String with Special Operations I
// Difficulty: Medium
// Tags     : String, Simulation
// URL      : https://leetcode.com/problems/process-string-with-special-operations-i/
// Solved on: 2026-04-09 00:16
// ──────────────────────────────────────────────────

class Solution {
public:
    string processStr(string s) {
        string r;  
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                if (!r.empty()) {
                    r.pop_back();  
                }
            }
            else if (s[i] == '#') {
                r += r;

            }
            else if (s[i] == '%') {
                reverse(r.begin(), r.end());  
            }
            else {
                r.push_back(s[i]);  
            }
        }
        return r;
    }
};


// Auto-commit update
