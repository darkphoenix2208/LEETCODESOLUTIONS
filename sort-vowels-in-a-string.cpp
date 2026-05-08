// Problem  : Sort Vowels in a String
// Difficulty: Medium
// Tags     : String, Sorting
// URL      : https://leetcode.com/problems/sort-vowels-in-a-string/
// Solved on: 2026-04-09 00:12
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<pair<int, char>> collectVowels(const string &s) {
        vector<pair<int, char>> vowelsFound;
        string vowels = "aeiouAEIOU";

        for (int i = 0; i < s.size(); i++) {
            if (vowels.find(s[i]) != string::npos) {
                vowelsFound.push_back({i, s[i]});
            }
        }
        return vowelsFound;
    }

    string sortVowels(string s) {
        vector<pair<int, char>> t = collectVowels(s);

        vector<char> upper, lower;
        for (auto &p : t) {
            if (isupper(p.second))
                upper.push_back(p.second);
            else
                lower.push_back(p.second);
        }

        sort(upper.begin(), upper.end());
        sort(lower.begin(), lower.end());

        vector<char> sortedVowels;
        sortedVowels.insert(sortedVowels.end(), upper.begin(), upper.end());
        sortedVowels.insert(sortedVowels.end(), lower.begin(), lower.end());

        for (int i = 0; i < t.size(); i++) {
            s[t[i].first] = sortedVowels[i];
        }

        return s;
    }
};

// Auto-commit update
