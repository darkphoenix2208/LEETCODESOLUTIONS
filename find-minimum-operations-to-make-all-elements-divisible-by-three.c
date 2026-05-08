// Problem  : Find Minimum Operations to Make All Elements Divisible by Three
// Difficulty: Easy
// Tags     : Array, Math
// URL      : https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/
// Solved on: 2026-04-09 00:04
// ──────────────────────────────────────────────────

int minimumOperations(int* nums, int numsSize) {
    int c=0;
    int i;
    for (i=0; i<numsSize; i++) {
        if (nums[i]%3==0) {
            continue;
        }
        else {
            c=c+1;
        }
    }
    return c;
}

// Auto-commit update
