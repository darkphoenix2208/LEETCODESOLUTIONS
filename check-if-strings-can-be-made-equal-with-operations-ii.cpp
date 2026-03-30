// Problem  : Check if Strings Can be Made Equal With Operations II
// Difficulty: Medium
// Tags     : Hash Table, String, Sorting
// URL      : https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/
// Solved on: 2026-05-08 21:49
// ──────────────────────────────────────────────────

class Solution {
public:
    bool checkStrings(string a,string b){
        vector<int> x(26),y(26),p(26),q(26);

        for(int i=0;i<a.size();i++){
            if(i%2==0){
                x[a[i]-'a']++;
                y[b[i]-'a']++;
            }
            else{
                p[a[i]-'a']++;
                q[b[i]-'a']++;
            }
        }

        return x==y && p==q;
    }
};

// Auto-commit update
