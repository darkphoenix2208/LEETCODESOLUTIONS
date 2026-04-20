// Problem  : Two Furthest Houses With Different Colors
// Difficulty: Easy
// Tags     : Array, Greedy
// URL      : https://leetcode.com/problems/two-furthest-houses-with-different-colors/
// Solved on: 2026-05-08 21:48
// ──────────────────────────────────────────────────

class Solution {
public:
    int maxDistance(vector<int>& a) {
        int n = a.size();
        int ans = 0;

        for(int i=n-1;i>=0;i--){
            if(a[i]!=a[0]){
                ans = max(ans, i);
                break;
            }
        }

        for(int i=0;i<n;i++){
            if(a[i]!=a[n-1]){
                ans = max(ans, n-1-i);
                break;
            }
        }

        return ans;
    }
};

// Auto-commit update
