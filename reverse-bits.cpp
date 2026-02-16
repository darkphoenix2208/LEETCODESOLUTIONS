// Problem  : Reverse Bits
// Difficulty: Easy
// Tags     : Divide and Conquer, Bit Manipulation
// URL      : https://leetcode.com/problems/reverse-bits/
// Solved on: 2026-05-08 21:52
// ──────────────────────────────────────────────────

class Solution {
public:
    int reverseBits(int m) {
        string s="";
        int a=m;
        while(a!=0){
            if(a%2==1){
                s+='1';
            }
            else{
            s+='0';
            }
            a/=2;
        }
         reverse(s.begin(),s.end());
        while(s.length()!=32){
            s='0'+s;
        }
        cout<<s<<"\n";
       reverse(s.begin(),s.end());
        cout<<s<<"\n";
        int ans=0;
        int n=s.length();
        int c=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1'){
                ans+=pow(2,c);
            }
            c++;
        }
        return ans;
    }
};

// Auto-commit update
