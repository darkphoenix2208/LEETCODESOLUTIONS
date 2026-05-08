// Problem  : Find Closest Person
// Difficulty: Easy
// Tags     : Math
// URL      : https://leetcode.com/problems/find-closest-person/
// Solved on: 2026-04-09 00:13
// ──────────────────────────────────────────────────

class Solution {
public:
    int findClosest(int x, int y, int z) {
        int a =abs(x-z);
        int b=abs(y-z);
        if(a==b){
            return 0;
        }
        else if(a>b){
            return 2;
        }
        else{return 1;}
        return -1;
    }
};

// Auto-commit update
