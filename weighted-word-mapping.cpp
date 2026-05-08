// Problem  : Weighted Word Mapping
// Difficulty: Easy
// Tags     : Array, String, Simulation
// URL      : https://leetcode.com/problems/weighted-word-mapping/
// Solved on: 2026-04-08 23:53
// ──────────────────────────────────────────────────

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(int i=0;i<words.size();i++){
            int a=0;
            for(int j=0;j<words[i].size();j++){
                a+=weights[words[i][j]-'a'];
            }
            a%=26;
            
            ans+=char('z'-a);
        }
        return ans;
    }
};

// Auto-commit update
