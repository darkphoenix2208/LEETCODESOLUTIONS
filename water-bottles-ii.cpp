// Problem  : Water Bottles II
// Difficulty: Medium
// Tags     : Math, Simulation
// URL      : https://leetcode.com/problems/water-bottles-ii/
// Solved on: 2026-04-09 00:10
// ──────────────────────────────────────────────────

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drank = numBottles;
        int empty = numBottles;
        while (empty >= numExchange) {
            
            empty -= numExchange;
            
            drank += 1;
            empty += 1;
        
            numExchange++;
        }
        return drank;
    }
};


// Auto-commit update
