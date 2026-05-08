// Problem  : Maximum 69 Number
// Difficulty: Easy
// Tags     : Math, Greedy
// URL      : https://leetcode.com/problems/maximum-69-number/
// Solved on: 2026-04-09 00:15
// ──────────────────────────────────────────────────

class Solution {
public:
    int maximum69Number(int num) {
        string str = to_string(num);
        for (int i = 0; i < (int)str.size(); i++) {
            if (str[i] == '6') {
                str[i] = '9';
                break;  
            }
        }
        return stoi(str);
    }
};


// Auto-commit update
