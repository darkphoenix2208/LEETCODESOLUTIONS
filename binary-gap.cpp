// Problem  : Binary Gap
// Difficulty: Easy
// Tags     : Bit Manipulation
// URL      : https://leetcode.com/problems/binary-gap/
// Solved on: 2026-05-08 21:52
// ──────────────────────────────────────────────────

class Solution {
public:
    int binaryGap(int n) {
        string s="";
        while(n!=0){
            if(n%2==0){
                s+='0';
            }
            else{
              s+='1';  
            }
            n/=2;
        }

        vector<int>v;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                v.push_back(i);
            }
        }
        int ans=0;
        for(int i=0;i<v.size()-1;i++){
            ans=max(ans,v[i+1]-v[i]);
        }
        return ans;
    }
};

// Auto-commit update
