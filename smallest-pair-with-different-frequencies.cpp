// Problem  : Smallest Pair With Different Frequencies
// Difficulty: Easy
// Tags     : Array, Hash Table, Counting
// URL      : https://leetcode.com/problems/smallest-pair-with-different-frequencies/
// Solved on: 2026-05-08 21:51
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(101,0);
        vector<int>ans(2,-1);
        
        for(int i=0;i<n;i++){
            v[nums[i]]++;
        }
        bool a=false;
        for(int i=0;i<v.size() && !a;i++){
            for(int j=i+1;j<v.size() && !a;j++){
                if(v[i]!=v[j] && v[i]!=0 && v[j]!=0){
                    ans[0]=i;
                     ans[1]=j;
                    a=true;
                    break;
                }
            }
        }
        return ans;
    }
};

// Auto-commit update
