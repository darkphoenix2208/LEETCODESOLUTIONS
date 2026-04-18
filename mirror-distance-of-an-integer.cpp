// Problem  : Mirror Distance of an Integer
// Difficulty: Easy
// Tags     : Math
// URL      : https://leetcode.com/problems/mirror-distance-of-an-integer/
// Solved on: 2026-05-08 21:48
// ──────────────────────────────────────────────────

class Solution {
public:
    int reverseNum(int x){
        int r = 0;
        while(x){
            r = r * 10 + x % 10;
            x /= 10;
        }
        return r;
    }

    int mirrorDistance(int n) {
        int r = reverseNum(n);
        return abs(n - r);
    }
};

// Auto-commit update
