// Problem  : Final Value of Variable After Performing Operations
// Difficulty: Easy
// Tags     : Array, String, Simulation
// URL      : https://leetcode.com/problems/final-value-of-variable-after-performing-operations/
// Solved on: 2026-04-09 00:07
// ──────────────────────────────────────────────────

class Solution {
public:
    int finalValueAfterOperations(vector<string>& s) {
        int x=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=="X++" || s[i]=="++X"){
                x++;
            }
            else{
                x--;
            }
        }
        return x;
    }
};

// Auto-commit update
