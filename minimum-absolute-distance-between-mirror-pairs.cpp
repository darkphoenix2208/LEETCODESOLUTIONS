// Problem  : Minimum Absolute Distance Between Mirror Pairs
// Difficulty: Medium
// Tags     : Array, Hash Table, Math
// URL      : https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/
// Solved on: 2026-05-08 21:48
// ──────────────────────────────────────────────────

class Solution {
public:
    int rev(int x){
        int r = 0;
        while(x){
            r = r * 10 + x % 10;
            x /= 10;
        }
        return r;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans = INT_MAX;

        for(int i = 0; i < nums.size(); i++){
            if(mp.count(nums[i])){
                ans = min(ans, i - mp[nums[i]]);
            }

            int r = rev(nums[i]);
            mp[r] = i;
        }

        if(ans == INT_MAX) return -1;
        return ans;
    }
};

// Auto-commit update
