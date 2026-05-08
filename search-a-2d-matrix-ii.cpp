// Problem  : Search a 2D Matrix II
// Difficulty: Medium
// Tags     : Array, Binary Search, Divide and Conquer, Matrix
// URL      : https://leetcode.com/problems/search-a-2d-matrix-ii/
// Solved on: 2026-04-09 00:18
// ──────────────────────────────────────────────────

class Solution {
public:
    bool search(vector<int>& matrix, int target){
        int low=0; int high=matrix.size()-1;
        while(low<=high){
int mid=(low+high)/2;
if(matrix[mid]>target){
    high=mid-1;
}
else if(matrix[mid]<target){
    low=mid+1;
}
else{
    return true;
}
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        for(int i=0;i<matrix.size();i++){
            if(search(matrix[i],target)){
                return true;
            }
        }

return false;
    }
};

// Auto-commit update
