// Problem  : Rotated Digits
// Difficulty: Medium
// Tags     : Math, Dynamic Programming
// URL      : https://leetcode.com/problems/rotated-digits/
// Solved on: 2026-05-08 21:47
// ──────────────────────────────────────────────────

class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;

        for(int i = 1; i <= n; i++){
            int x = i;
            bool ok = true;
            bool diff = false;

            while(x){
                int d = x % 10;

                if(d == 3 || d == 4 || d == 7){
                    ok = false;
                    break;
                }

                if(d == 2 || d == 5 || d == 6 || d == 9){
                    diff = true;
                }

                x /= 10;
            }

            if(ok && diff) ans++;
        }

        return ans;
    }
};

// Auto-commit update
