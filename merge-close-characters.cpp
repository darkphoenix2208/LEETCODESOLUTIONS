// Problem  : Merge Close Characters
// Difficulty: Medium
// Tags     : Hash Table, String
// URL      : https://leetcode.com/problems/merge-close-characters/
// Solved on: 2026-05-08 21:51
// ──────────────────────────────────────────────────

class Solution {
public:
    string mergeCharacters(string s, int k) {
        bool ans=true;
        while(ans){
            ans=false;
            for(int i=0;i<s.length();i++){
            for(int j=i+1;j<s.length();j++){
                if(s[i]==s[j] && j-i<=k){
                    s.erase(j,1);
                    ans=true;
                }
                if(j-i>k){
                    break;
                }
                
            }
                if(!ans){
                    
                }
                else{
                    break;
                }
            }
        }
        return s;
    }
};

// Auto-commit update
