// Problem  : Minimum Number of Flips to Make the Binary String Alternating
// Difficulty: Medium
// Tags     : String, Dynamic Programming, Sliding Window
// URL      : https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/
// Solved on: 2026-05-08 21:51
// ──────────────────────────────────────────────────

class Solution {
public:
int minFlips(string s) {
    int n=s.size();
    string t=s+s;

    int ans=1e9;
    int diff1=0,diff2=0;

    for(int i=0;i<t.size();i++){
        char c1=(i%2)?'1':'0';
        char c2=(i%2)?'0':'1';

        if(t[i]!=c1) diff1++;
        if(t[i]!=c2) diff2++;

        if(i>=n){
            char p1=((i-n)%2)?'1':'0';
            char p2=((i-n)%2)?'0':'1';

            if(t[i-n]!=p1) diff1--;
            if(t[i-n]!=p2) diff2--;
        }

        if(i>=n-1){
            ans=min(ans,min(diff1,diff2));
        }
    }

    return ans;
}
};

// Auto-commit update
