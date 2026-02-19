// Problem  : Count Binary Substrings
// Difficulty: Easy
// Tags     : Two Pointers, String
// URL      : https://leetcode.com/problems/count-binary-substrings/
// Solved on: 2026-05-08 21:52
// ──────────────────────────────────────────────────

class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<pair<char,int>> v;
        
        char c = s[0];
        int a = 0;
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] != c){
                v.push_back({c, a});
                c = s[i];
                a = 1;
            }
            else{
                a++;
            }
        }
        
        v.push_back({c, a});
        
        int ans = 0;
        
        for(int i = 0; i < v.size() - 1; i++){
            ans += min(v[i].second, v[i+1].second);
        }
        
        return ans;
    }
};


// Auto-commit update
