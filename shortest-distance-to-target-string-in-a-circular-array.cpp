// Problem  : Shortest Distance to Target String in a Circular Array
// Difficulty: Easy
// Tags     : Array, String
// URL      : https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/
// Solved on: 2026-05-08 21:48
// ──────────────────────────────────────────────────

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int start) {
        int n = words.size();
        for (int i = 0; i <= (n >> 1); i++)
            if (words[(start + i) % n] == target |
                words[(start - i + n) % n] == target)
                return i;
                
        return -1;
    }
};

// Auto-commit update
