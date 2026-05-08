// Problem  : Maximum Number of Words You Can Type
// Difficulty: Easy
// Tags     : Hash Table, String
// URL      : https://leetcode.com/problems/maximum-number-of-words-you-can-type/
// Solved on: 2026-04-09 00:11
// ──────────────────────────────────────────────────

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<string> s;
        int a = 0;
        for (int i = 0; i <= text.size(); i++) {
            if (i == text.size() || text[i] == ' ') {  
                s.push_back(text.substr(a, i - a));  
                a = i + 1; 
            }
        }

        int count = 0;

        for (string t : s) {
            bool bad = false;  
            for (char c : t) {
                if (brokenLetters.find(c) != string::npos) {  
                    bad = true; 
                    break;       
                }
            }
            if (!bad) {
                count++;
            }
        }

        return count;
    }
};


// Auto-commit update
