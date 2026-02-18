// Problem  : Binary Number with Alternating Bits
// Difficulty: Easy
// Tags     : Bit Manipulation
// URL      : https://leetcode.com/problems/binary-number-with-alternating-bits/
// Solved on: 2026-05-08 21:52
// ──────────────────────────────────────────────────

class Solution {
public:
    bool hasAlternatingBits(int n) {
        string s="";
        while(n!=0){
            if(n%2==1){
                    s+='1';
            }
            if(n%2==0){
                    s+='0';
            }
            n/=2;
        }
        bool ans=true;
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1]){
                ans=false;
                break;
            }
        }
        return ans;
    }
};

// Auto-commit update
