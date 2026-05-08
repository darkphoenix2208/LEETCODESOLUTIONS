// Problem  : Minimum Time to Make Rope Colorful
// Difficulty: Medium
// Tags     : Array, String, Dynamic Programming, Greedy
// URL      : https://leetcode.com/problems/minimum-time-to-make-rope-colorful/
// Solved on: 2026-04-09 00:05
// ──────────────────────────────────────────────────

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int totalTime = 0;
        
        for (int i = 1; i < n; i++) {
            if (colors[i] == colors[i - 1]) {
                totalTime += min(neededTime[i], neededTime[i - 1]);
                
                
                neededTime[i] = max(neededTime[i], neededTime[i - 1]);
            }
        }
        
        return totalTime;
    }
};

// Auto-commit update
