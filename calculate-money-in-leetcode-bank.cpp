// Problem  : Calculate Money in Leetcode Bank
// Difficulty: Easy
// Tags     : Math
// URL      : https://leetcode.com/problems/calculate-money-in-leetcode-bank/
// Solved on: 2026-04-09 00:06
// ──────────────────────────────────────────────────

class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        int monday = 1;
        
        while (n > 0) {
            for (int day = 0; day < min(n, 7); day++) {
                ans += monday + day;
            }
            
            n -= 7;
            monday++;
        }
        
        return ans;
    }
};

// Auto-commit update
