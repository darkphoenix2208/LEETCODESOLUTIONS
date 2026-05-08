// Problem  : Find Smallest Letter Greater Than Target
// Difficulty: Easy
// Tags     : Array, Binary Search
// URL      : https://leetcode.com/problems/find-smallest-letter-greater-than-target/
// Solved on: 2026-04-08 23:54
// ──────────────────────────────────────────────────

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(int i=0;i<letters.size();i++){
            if(letters[i]>target){
                return letters[i];
            }
        }
          return letters[0];
    }
};

// Auto-commit update
