// Problem  : Number of Steps to Reduce a Number in Binary Representation to One
// Difficulty: Medium
// Tags     : String, Bit Manipulation, Simulation
// URL      : https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/
// Solved on: 2026-05-08 21:52
// ──────────────────────────────────────────────────

class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;
        
        for (int i = s.size() - 1; i > 0; i--) {
            int bit = (s[i] - '0') + carry;
            
            if (bit % 2 == 0) {
                steps += 1;      
            } else {
                steps += 2;      
                carry = 1;
            }
        }
        
        if (carry) steps += 1;
        
        return steps;
    }
};

// Auto-commit update
