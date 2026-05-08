// Problem  : Find the Number of Ways to Place People I
// Difficulty: Medium
// Tags     : Array, Math, Geometry, Sorting, Enumeration
// URL      : https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/
// Solved on: 2026-04-09 00:13
// ──────────────────────────────────────────────────

class Solution {
public:
bool check(vector<vector<int>>& points,int i,int j){
    int n=points.size();
    for(int k=0;k<n;k++){
        if(k==i || k==j) continue;
        if(points[k][0] >= points[j][0] && points[k][0] <= points[i][0] &&
           points[k][1] >= points[i][1] && points[k][1] <= points[j][1]) {
            return false;
        }
    }
    return true;
}

    int numberOfPairs(vector<vector<int>>& points) {
        
        int count=0;
        int n=points.size();
        if(n==1){
            return count;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==i)continue;
                if(points[i][0]>=points[j][0] && points[i][1]<=points[j][1]){
                    if(n>2){
if(check(points,i,j)){
    count++;
}
                    }
else{
count++;
}
                    
                }
            }
        }
        return count;
    }
};

// Auto-commit update
