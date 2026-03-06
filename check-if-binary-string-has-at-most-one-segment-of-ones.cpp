// Problem  : Check if Binary String Has at Most One Segment of Ones
// Difficulty: Easy
// Tags     : String
// URL      : https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/
// Solved on: 2026-05-08 21:51
// ──────────────────────────────────────────────────

class Solution {
public:
    bool checkOnesSegment(string s) {
        int segments = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1' && (i == 0 || s[i-1] == '0')) {
                segments++;
            }

            if(segments > 1) return false;
        }

        return true;
    }
};

// Auto-commit update
