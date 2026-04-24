// Problem  : Furthest Point From Origin
// Difficulty: Easy
// Tags     : String, Counting
// URL      : https://leetcode.com/problems/furthest-point-from-origin/
// Solved on: 2026-05-08 21:47
// ──────────────────────────────────────────────────

class Solution {
public:
    int furthestDistanceFromOrigin(string s) {
        int l=0,r=0,u=0;

        for(char c:s){
            if(c=='L') l++;
            else if(c=='R') r++;
            else u++;
        }

        return abs(r-l)+u;
    }
};

// Auto-commit update
