// Problem  : Minimum Add to Make Parentheses Valid
// Difficulty: Medium
// Tags     : String, Stack, Greedy
// URL      : https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
// Solved on: 2026-04-09 00:05
// ──────────────────────────────────────────────────

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> a;
        int c = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                a.push(s[i]);
            } else {

                if (!a.empty() && a.top() == '(') {
                    a.pop();
                } else {
                    c++; 
                }
            }
        }

      
        while (!a.empty()) {
            a.pop();
            c++;
        }

        return c;
    }
};


// Auto-commit update
