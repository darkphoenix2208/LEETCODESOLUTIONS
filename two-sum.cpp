// Problem  : Two Sum
// Difficulty: Easy
// Tags     : Array, Hash Table
// URL      : https://leetcode.com/problems/two-sum/
// Solved on: 2026-05-08 21:50
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mpp;
        vector<int>a;
        for(int i=0;i<nums.size();i++){
            if(mpp.find(target-nums[i])!=mpp.end()){
             a.push_back(i);
             a.push_back(mpp[target-nums[i]]);
             break;
            }
            else{
                  mpp[nums[i]]=i;
            }
        }
return a;
    }
};

// Auto-commit update
