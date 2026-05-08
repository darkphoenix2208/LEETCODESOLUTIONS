// Problem  : Vowel Spellchecker
// Difficulty: Medium
// Tags     : Array, Hash Table, String
// URL      : https://leetcode.com/problems/vowel-spellchecker/
// Solved on: 2026-04-09 00:11
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseInsensitive;
        unordered_map<string, string> devoweled;

        auto toLower = [](string s) {
            for (auto &c : s) c = tolower(c);
            return s;
        };

        auto maskVowels = [&](string s) {
            for (auto &c : s) {
                char lower = tolower(c);
                if (lower=='a' || lower=='e' || lower=='i' || lower=='o' || lower=='u')
                    c = '*';
                else
                    c = lower;
            }
            return s;
        };

        for (string w : wordlist) {
            string lower = toLower(w);
            string masked = maskVowels(w);
            if (caseInsensitive.find(lower) == caseInsensitive.end())
                caseInsensitive[lower] = w;
            if (devoweled.find(masked) == devoweled.end())
                devoweled[masked] = w;
        }

        vector<string> res;
        for (string q : queries) {
            if (exact.count(q)) {
                res.push_back(q);
                continue;
            }
            string lower = toLower(q);
            if (caseInsensitive.count(lower)) {
                res.push_back(caseInsensitive[lower]);
                continue;
            }
            string masked = maskVowels(q);
            if (devoweled.count(masked)) {
                res.push_back(devoweled[masked]);
                continue;
            }
            res.push_back(""); 
        }

        return res;
    }
};


// Auto-commit update
