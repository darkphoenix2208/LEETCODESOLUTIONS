// Problem  : Check if Strings Can be Made Equal With Operations I
// Difficulty: Easy
// Tags     : String
// URL      : https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/
// Solved on: 2026-05-08 21:49
// ──────────────────────────────────────────────────

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]){
                swap(s1[i],s1[i+2]);
            }
        }
        return s1==s2;
    }
};

// Auto-commit update
