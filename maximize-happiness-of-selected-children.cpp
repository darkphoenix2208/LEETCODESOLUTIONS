// Problem  : Maximize Happiness of Selected Children
// Difficulty: Medium
// Tags     : Array, Greedy, Sorting
// URL      : https://leetcode.com/problems/maximize-happiness-of-selected-children/
// Solved on: 2026-04-09 00:01
// ──────────────────────────────────────────────────

class Solution {
public:
    long long maximumHappinessSum(vector<int>& v, int k) {
        sort(v.begin(),v.end());
        long long  i=v.size()-1;
        long long  c=0;
        long long  ans=0;
        while(k--){
            if(v[i]-c<0){
                break;
            }
            ans+=v[i]-c;
            c++;
            i--;
        }
        return ans;
    }
};

// Auto-commit update
