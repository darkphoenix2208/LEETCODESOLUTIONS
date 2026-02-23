// Problem  : Check If a String Contains All Binary Codes of Size K
// Difficulty: Medium
// Tags     : Hash Table, String, Bit Manipulation, Rolling Hash, Hash Function
// URL      : https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
// Solved on: 2026-05-08 21:52
// ──────────────────────────────────────────────────

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        
        for(int i = 0; i + k <= s.length(); i++){
            st.insert(s.substr(i, k));
        }
        
        return st.size() == (1 << k);
    }
};

// Auto-commit update
