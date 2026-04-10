// Problem  : Minimum Distance Between Three Equal Elements I
// Difficulty: Easy
// Tags     : Array, Hash Table
// URL      : https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i/
// Solved on: 2026-05-08 21:48
// ──────────────────────────────────────────────────

class Solution {
public:
int minimumDistance(vector<int>& nums) {
    
    unordered_map<int, vector<int>> mp;
    
    int n = nums.size();
    
    for(int i = 0; i < n; i++){
        mp[nums[i]].push_back(i);
    }
    
    int ans = INT_MAX;
    
    for(auto &it : mp){
        vector<int> &v = it.second;
        
        if(v.size() < 3) continue;
        
        for(int i = 0; i + 2 < v.size(); i++){
            int dist = 2 * (v[i+2] - v[i]);
            ans = min(ans, dist);
        }
    }
    
    if(ans == INT_MAX) return -1;
    return ans;
}
};

// Auto-commit update
