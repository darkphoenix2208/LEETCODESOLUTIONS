// Problem  : Divide an Array Into Subarrays With Minimum Cost I
// Difficulty: Easy
// Tags     : Array, Sorting, Enumeration
// URL      : https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/
// Solved on: 2026-04-08 23:54
// ──────────────────────────────────────────────────

class Solution {
public:
    int minimumCost(vector<int>& v) {
        int a=v[0];
        sort(v.begin(),v.end());
       
        auto it = find(v.begin(),v.end(),a);
    if (it != v.end()) {
        v.erase(it);   
    }
    //cout<<a<<v[0]<<v[1];
        return v[0]+v[1]+a;
    }
};

// Auto-commit update
