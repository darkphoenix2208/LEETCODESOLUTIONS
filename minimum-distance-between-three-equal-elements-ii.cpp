// Problem  : Minimum Distance Between Three Equal Elements II
// Difficulty: Medium
// Tags     : Array, Hash Table
// URL      : https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/
// Solved on: 2026-05-08 21:48
// ──────────────────────────────────────────────────

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        map<int,vector<int>>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]].push_back(i);
        }
        int ans=INT_MAX;
    
     bool a=false;
        for(auto & p:mpp){
            if(p.second.size()>2){
                for(int i=0;i<p.second.size()-2;i++){

                    ans=min(ans,abs(p.second[i]-p.second[i+1])+abs(p.second[i+1]-p.second[i+2])+abs(p.second[i+2]-p.second[i]));
                    a=true;
                }
            }
        }
        if(!a){
            return -1;
        }

        return ans;
    }
};

// Auto-commit update
