// Problem  : Robot Return to Origin
// Difficulty: Easy
// Tags     : String, Simulation
// URL      : https://leetcode.com/problems/robot-return-to-origin/
// Solved on: 2026-05-08 21:49
// ──────────────────────────────────────────────────

class Solution {
public:
    bool judgeCircle(string m) {
        int u=0,d=0,l=0,r=0;

        for(char c:m){
            if(c=='U') u++;
            else if(c=='D') d++;
            else if(c=='L') l++;
            else r++;
        }

        return (u==d && l==r);
    }
};

// Auto-commit update
