// Problem  : Water Bottles
// Difficulty: Easy
// Tags     : Math, Simulation
// URL      : https://leetcode.com/problems/water-bottles/
// Solved on: 2026-04-09 00:10
// ──────────────────────────────────────────────────

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalDrank = numBottles;
        int empty = numBottles;

        while (empty >= numExchange) {
            int newBottles = empty / numExchange;
            totalDrank += newBottles;
            empty = (empty % numExchange) + newBottles;
        }

        return totalDrank;
    }
};


// Auto-commit update
