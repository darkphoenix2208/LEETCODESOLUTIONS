// Problem  : 1-bit and 2-bit Characters
// Difficulty: Easy
// Tags     : Array
// URL      : https://leetcode.com/problems/1-bit-and-2-bit-characters/
// Solved on: 2026-04-09 00:04
// ──────────────────────────────────────────────────

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = bits.size() - 2;
        while (i >= 0 && bits[i] > 0) {
            i--;
        }
        return (bits.size() - i) % 2 == 0;
    }
};

// Auto-commit update
