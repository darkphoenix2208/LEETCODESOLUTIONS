// Problem  : Vowels Game in a String
// Difficulty: Medium
// Tags     : Math, String, Brainteaser, Game Theory
// URL      : https://leetcode.com/problems/vowels-game-in-a-string/
// Solved on: 2026-04-09 00:12
// ──────────────────────────────────────────────────

class Solution {
public:
    int countVowels(const string& str) {
    string vowels = "aeiou";
    int count = 0;

    for (char ch : str) {
        if (vowels.find(ch) != string::npos) {
            count++;
        }
    }
    return count;
}
    bool doesAliceWin(string s) {
        int a=countVowels(s);
        if(a==0 || (a&1==0)) return false;
        else{
            return true;
        }
    }
};

// Auto-commit update
