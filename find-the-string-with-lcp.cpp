// Problem  : Find the String with LCP
// Difficulty: Hard
// Tags     : Array, String, Dynamic Programming, Greedy, Union-Find, Matrix
// URL      : https://leetcode.com/problems/find-the-string-with-lcp/
// Solved on: 2026-05-08 21:49
// ──────────────────────────────────────────────────

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n=lcp.size();

        string s(n,'#');

        char c='a';

        for(int i=0;i<n;i++){
            if(s[i]!='#') continue;

            if(c>'z') return "";

            for(int j=i;j<n;j++){
                if(lcp[i][j]>0){
                    s[j]=c;
                }
            }

            c++;
        }

        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int val=0;

                if(s[i]==s[j]){
                    val=1;
                    if(i+1<n && j+1<n){
                        val+=lcp[i+1][j+1];
                    }
                }

                if(lcp[i][j]!=val){
                    return "";
                }
            }
        }

        return s;
    }
};

// Auto-commit update
