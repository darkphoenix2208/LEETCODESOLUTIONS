// Problem  : Count Collisions on a Road
// Difficulty: Medium
// Tags     : String, Stack, Simulation
// URL      : https://leetcode.com/problems/count-collisions-on-a-road/
// Solved on: 2026-04-09 00:03
// ──────────────────────────────────────────────────

class Solution {
public:
    int countCollisions(string directions) {
        int res = 0;
        int flag = -1;
        for (auto c : directions) {
            if (c == 'L') {
                if (flag >= 0) {
                    res += flag + 1;
                    flag = 0;
                }
            } else if (c == 'S') {
                if (flag > 0) {
                    res += flag;
                }
                flag = 0;
            } else {
                if (flag >= 0) {
                    flag++;
                } else {
                    flag = 1;
                }
            }
        }
        return res;
    }
};

// Auto-commit update
