// Problem  : Gas Station
// Difficulty: Medium
// Tags     : Array, Greedy
// URL      : https://leetcode.com/problems/gas-station/
// Solved on: 2026-04-09 00:06
// ──────────────────────────────────────────────────

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total = 0, tank = 0, start = 0;
        
        for (int i = 0; i < n; ++i) {
            int diff = gas[i] - cost[i];
            total += diff;
            tank += diff;
            
            if (tank < 0) {
                
                start = i + 1;
                tank = 0;
            }
        }
        
    
        return total >= 0 ? start : -1;
    }
};

// Auto-commit update
