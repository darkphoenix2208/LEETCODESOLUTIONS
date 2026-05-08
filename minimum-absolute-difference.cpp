// Problem  : Minimum Absolute Difference
// Difficulty: Easy
// Tags     : Array, Sorting
// URL      : https://leetcode.com/problems/minimum-absolute-difference/
// Solved on: 2026-04-08 23:55
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>ans;
        int a=INT_MAX;
    sort(arr.begin(),arr.end());
for(int i=0;i<n-1;i++){

a=min(a,abs(arr[i]-arr[i+1]));
        
    }

for(int i=0;i<n-1;i++){
  
        if(abs(arr[i]-arr[i+1])==a){
            ans.push_back({arr[i],arr[i+1]});
        }
        }

sort(ans.begin(),ans.end());


        return ans;
    }
};

// Auto-commit update
