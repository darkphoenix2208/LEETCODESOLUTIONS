// Problem  : Climbing Stairs
// Difficulty: Easy
// Tags     : Math, Dynamic Programming, Memoization
// URL      : https://leetcode.com/problems/climbing-stairs/
// Solved on: 2026-04-09 00:17
// ──────────────────────────────────────────────────

class Solution {
public:
    int climbStairs(int n) {
         int prev2 = 1;
  int prev = 1;
  
  for(int i=2; i<=n; i++){
      int cur_i = prev2+ prev;
      prev2 = prev;
      prev= cur_i;
  }
  return prev;
    }
};

// Auto-commit update
