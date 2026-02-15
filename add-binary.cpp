// Problem  : Add Binary
// Difficulty: Easy
// Tags     : Math, String, Bit Manipulation, Simulation
// URL      : https://leetcode.com/problems/add-binary/
// Solved on: 2026-05-08 21:52
// ──────────────────────────────────────────────────

class Solution {
public:
    string addBinary(string a, string b) {
        int l=a.length()-1;
        int r=b.length()-1;
        string ans="";
        if(l>r){
            string s="";
            for(int i=0;i<l-r;i++){
                s+='0';
            }
            b=s+b;
        }
         if(l<r){
            string s="";
            for(int i=0;i<r-l;i++){
                s+='0';
            }
           a=s+a;
        }
        int exp=0;
         l=a.length()-1;
       r=b.length()-1;
        while(l>=0 && r>=0){
            if(a[l]=='1' && b[r]=='1'&& exp==1){
                ans+='1';
                exp=1;
            }
            else if(a[l]=='1' && b[r]=='0'&& exp==1){
ans+='0';
exp=1;
            }
            else if(a[l]=='0' && b[r]=='1'&& exp==1){
                ans+='0';
                exp=1;
            }
            else if(a[l]=='0' && b[r]=='0'&& exp==1){
                ans+='1';
                exp=0;
            }
             else if(a[l]=='1' && b[r]=='1'&& exp==0){
                ans+='0';
                exp=1;
            }
             else if(a[l]=='1' && b[r]=='0'&& exp==0){
                ans+='1';
                exp=0;
            }
             else if(a[l]=='0' && b[r]=='1'&& exp==0){
                ans+='1';
                exp=0;
            }
             else if(a[l]=='0' && b[r]=='0'&& exp==0){
                ans+='0';
                exp=0;
            }
            cout<<ans<<"\n";
            l--;
            r--;
        }
        reverse(ans.begin(),ans.end());
        if(exp==1){
            ans='1'+ans;
                    }
        return ans;
    }
};

// Auto-commit update
