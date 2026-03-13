// Problem  : Minimum Number of Seconds to Make Mountain Height Zero
// Difficulty: Medium
// Tags     : Array, Math, Binary Search, Greedy, Heap (Priority Queue)
// URL      : https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero/
// Solved on: 2026-05-08 21:51
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool check(long long mid,int h,vector<int>& w){

        long long total=0;

        for(int t:w){

            long double val=(long double)2*mid/t;

            long long x=(sqrt(1+4*val)-1)/2;

            total+=x;

            if(total>=h) return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {

        long long l=1,r=1e18,ans=r;

        while(l<=r){

            long long mid=l+(r-l)/2;

            if(check(mid,mountainHeight,workerTimes)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }

        return ans;
    }
};

// Auto-commit update
