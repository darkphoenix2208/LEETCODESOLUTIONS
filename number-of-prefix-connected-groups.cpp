// Problem  : Number of Prefix Connected Groups
// Difficulty: Medium
// Tags     : Array, Hash Table, String, Counting
// URL      : https://leetcode.com/problems/number-of-prefix-connected-groups/
// Solved on: 2026-05-08 21:53
// ──────────────────────────────────────────────────

class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        sort(words.begin(),words.end());
        int n=words.size();
        int ans=0;
        int cnt=1;
        for(int i=1;i<n;i++){
            if( words[i].size()>=k && words[i].size()>=k&&  words[i].compare(0,k,words[i-1],0,k)==0){
                cnt++;
            }
            else{
                if(cnt>1)ans++;
                cnt=1;
            }
        }
        if(cnt>1)ans++;
        return ans;
            
        
    }
};

// Auto-commit update
