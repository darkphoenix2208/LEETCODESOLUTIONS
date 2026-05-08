// Problem  : Find The Least Frequent Digit
// Difficulty: Easy
// Tags     : Array, Hash Table, Math, Counting
// URL      : https://leetcode.com/problems/find-the-least-frequent-digit/
// Solved on: 2026-04-09 00:14
// ──────────────────────────────────────────────────

class Solution {
public:
    int getLeastFrequentDigit(int n) {
        string s = to_string(n);
        
        vector<int> freq(10, 0);
        for (char ch : s) {
            freq[ch - '0']++;
        }
    
        int minFreq = INT_MAX;
        int ans = -1;
        for (int d = 0; d < 10; d++) {
            if (freq[d] > 0 && freq[d] < minFreq) {
                minFreq = freq[d];
                ans = d;
            }
        }
        
        return ans; 
    }
};


// Auto-commit update
