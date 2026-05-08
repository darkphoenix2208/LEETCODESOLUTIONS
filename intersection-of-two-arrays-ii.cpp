// Problem  : Intersection of Two Arrays II
// Difficulty: Easy
// Tags     : Array, Hash Table, Two Pointers, Binary Search, Sorting
// URL      : https://leetcode.com/problems/intersection-of-two-arrays-ii/
// Solved on: 2026-04-09 00:17
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
          std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    std::vector<int> result;

    std::set_intersection(
        a.begin(), a.end(),
        b.begin(), b.end(),
        std::back_inserter(result)
    );
    return result;
    }
};

// Auto-commit update
