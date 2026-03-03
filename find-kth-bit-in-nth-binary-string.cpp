// Problem  : Find Kth Bit in Nth Binary String
// Difficulty: Medium
// Tags     : String, Recursion, Simulation
// URL      : https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/
// Solved on: 2026-05-08 21:51
// ──────────────────────────────────────────────────

class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        for(int i = 2; i <= n; i++) {
            string t = s;
            reverse(t.begin(), t.end());
            for(char &c : t) c = (c == '0' ? '1' : '0');
            s = s + "1" + t;
        }
        return s[k - 1];
    }
};

// Auto-commit update
