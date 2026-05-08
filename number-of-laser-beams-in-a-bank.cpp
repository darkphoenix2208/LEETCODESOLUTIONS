// Problem  : Number of Laser Beams in a Bank
// Difficulty: Medium
// Tags     : Array, Math, String, Matrix
// URL      : https://leetcode.com/problems/number-of-laser-beams-in-a-bank/
// Solved on: 2026-04-09 00:06
// ──────────────────────────────────────────────────

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, ans = 0;
        
        for (string s : bank) {
            int count = 0;
            for (char c : s) {
                if (c == '1') {
                    count++;
                }
            }
            if (count != 0) {
                ans += (prev * count);
                prev = count;
            }
        }
        
        return ans;
    }
};

// Auto-commit update
