// Problem  : Words Within Two Edits of Dictionary
// Difficulty: Medium
// Tags     : Array, String, Trie
// URL      : https://leetcode.com/problems/words-within-two-edits-of-dictionary/
// Solved on: 2026-05-08 21:47
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<string> twoEditWords(vector<string>& q, vector<string>& d) {
        vector<string> r;

        for(auto &s:q){
            for(auto &t:d){
                int c=0;
                for(int i=0;i<s.size();i++){
                    if(s[i]!=t[i])c++;
                    if(c>2)break;
                }
                if(c<=2){
                    r.push_back(s);
                    break;
                }
            }
        }

        return r;
    }
};

// Auto-commit update
