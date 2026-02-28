// Problem  : Concatenation of Consecutive Binary Numbers
// Difficulty: Medium
// Tags     : Math, Bit Manipulation, Simulation
// URL      : https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/
// Solved on: 2026-05-08 21:51
// ──────────────────────────────────────────────────

class Solution {
public:
    int concatenatedBinary(int n) {
        long long mod = 1e9 + 7;
        long long ans = 0;
        
        for(int i = 1; i <= n; i++){
            int len = 0;
            int x = i;
            while(x > 0){
                len++;
                x >>= 1;
            }
            ans = ((ans << len) % mod + i) % mod;
        }
        
        return ans;
    }
};

// Auto-commit update
