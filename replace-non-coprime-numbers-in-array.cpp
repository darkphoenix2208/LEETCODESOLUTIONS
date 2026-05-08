// Problem  : Replace Non-Coprime Numbers in Array
// Difficulty: Hard
// Tags     : Array, Math, Stack, Number Theory
// URL      : https://leetcode.com/problems/replace-non-coprime-numbers-in-array/
// Solved on: 2026-04-09 00:11
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st; 
        for (int x : nums) {
            st.push_back(x);
            while (st.size() > 1) {
                int a = st.back();
                int b = st[st.size()-2];
                int g = gcd(a, b);
                if (g == 1) break; 
                long long merged = lcm((long long)a, (long long)b);
                st.pop_back();
                st.pop_back();
                st.push_back((int)merged);
            }
        }
        return st;
    }
};


// Auto-commit update
