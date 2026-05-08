// Problem  : Reverse Words in a String
// Difficulty: Medium
// Tags     : Two Pointers, String
// URL      : https://leetcode.com/problems/reverse-words-in-a-string/
// Solved on: 2026-04-09 00:20
// ──────────────────────────────────────────────────

class Solution {
public:
    string reverseWords(string s) {
    string word;
    vector<string> words;

    stringstream ss(s);
    while (ss >> word) {
        words.push_back(word);
    }
      reverse(words.begin(), words.end());

    // Join them back into a string
    string reversedStr = "";
    for (int i = 0; i < words.size(); i++) {
        reversedStr += words[i];
        if (i != words.size() - 1)
            reversedStr += " ";
    }
return reversedStr;

    }
};

// Auto-commit update
