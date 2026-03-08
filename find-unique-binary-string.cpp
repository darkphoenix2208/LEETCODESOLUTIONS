// Problem  : Find Unique Binary String
// Difficulty: Medium
// Tags     : Array, Hash Table, String, Backtracking
// URL      : https://leetcode.com/problems/find-unique-binary-string/
// Solved on: 2026-05-08 21:51
// ──────────────────────────────────────────────────

class Solution {
public:
string findDifferentBinaryString(vector<string>& nums) {
    int n=nums.size();
    string ans="";

    for(int i=0;i<n;i++){
        if(nums[i][i]=='0') ans+='1';
        else ans+='0';
    }

    return ans;
}
};

// Auto-commit update
