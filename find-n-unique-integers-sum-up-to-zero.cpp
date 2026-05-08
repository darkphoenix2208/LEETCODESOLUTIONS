// Problem  : Find N Unique Integers Sum up to Zero
// Difficulty: Easy
// Tags     : Array, Math
// URL      : https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/
// Solved on: 2026-04-09 00:13
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> sumZero(int n) {
        if(n&1){
vector<int>v={0};
n--;
int i=1,j=-1;
while(n){
    v.push_back(i);
     v.push_back(j);
     i++;
     j--;
     n-=2;
}
return v;
        }
        else{
               vector<int>v;
int i=1,j=-1;
while(n){
    v.push_back(i);
     v.push_back(j);
     i++;
     j--;
     n-=2;
}
return v;
        }
        vector<int>t;
        return t;
    }
};

// Auto-commit update
