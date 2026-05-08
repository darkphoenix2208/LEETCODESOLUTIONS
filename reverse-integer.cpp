// Problem  : Reverse Integer
// Difficulty: Medium
// Tags     : Math
// URL      : https://leetcode.com/problems/reverse-integer/
// Solved on: 2026-04-09 00:14
// ──────────────────────────────────────────────────

#include <string>
#include <algorithm>
#include <climits>

class Solution {
public:
    int reverse(int x) {
        bool isNegative = x < 0;
        std::string s = std::to_string(x);
        if (isNegative) s = s.substr(1);
        std::reverse(s.begin(), s.end());
        std::string limit = isNegative ? "2147483648" : "2147483647";
        if (s.length() > limit.length() || (s.length() == limit.length() && s > limit)) return 0;
        int result = 0;
        for (char c : s) result = result * 10 + (c - '0');
        return isNegative ? -result : result;
    }
};


// Auto-commit update
