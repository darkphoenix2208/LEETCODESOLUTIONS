// Problem  : Prime Number of Set Bits in Binary Representation
// Difficulty: Easy
// Tags     : Math, Bit Manipulation
// URL      : https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/
// Solved on: 2026-05-08 21:52
// ──────────────────────────────────────────────────

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
            int ans=0;
            for(int i=left;i<=right;i++){
               int a=0,b=0;
               int c=i;
               while(c!=0){
                if(c%2==1){
                    a++;
                }
                c=c/2;
               }
               bool an=true;
               for (int i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) {
            an=false;
            break;
        }
    }
    if(a==1){
        an=false;
    }
               if(an){
                cout<<i<<a<<"\n";
                ans++;
               }
            }

            return ans;
    }
};

// Auto-commit update
