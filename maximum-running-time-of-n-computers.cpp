// Problem  : Maximum Running Time of N Computers
// Difficulty: Hard
// Tags     : Array, Binary Search, Greedy, Sorting
// URL      : https://leetcode.com/problems/maximum-running-time-of-n-computers/
// Solved on: 2026-04-09 00:03
// ──────────────────────────────────────────────────

class Solution {
public:
    static long long maxRunTime(int n, vector<int>& batteries) {
        const long long sum=reduce(batteries.begin(), batteries.end(), 0LL);
        long long l=*min_element(batteries.begin(), batteries.end()), r=sum/n, ans=0;   

        while (l<=r) {
            long long mid=(l+r)>>1;
            long long reserve=0;

            for (int x : batteries)
                reserve+=min((long long)x, mid);

            if (reserve>=mid*n) {
                ans=mid;
                l=mid+1;     
            } 
            else 
                r=mid-1;
        }
        return ans;  
    }
};

// Auto-commit update
