// Problem  : Count of Smaller Numbers After Self
// Difficulty: Hard
// Tags     : Array, Binary Search, Divide and Conquer, Binary Indexed Tree, Segment Tree, Merge Sort, Ordered Set
// URL      : https://leetcode.com/problems/count-of-smaller-numbers-after-self/
// Solved on: 2026-04-09 00:20
// ──────────────────────────────────────────────────

class Solution {
public:
    void mergeSort(vector<pair<int, int>>& nums, vector<int>& counts, int left, int right) {
        if (right - left <= 1) return;
        
        int mid = left + (right - left) / 2;
        mergeSort(nums, counts, left, mid);
        mergeSort(nums, counts, mid, right);

        int j = mid, k = mid;
        vector<pair<int, int>> temp;

        for (int i = left; i < mid; ++i) {
            while (k < right && nums[k].first < nums[i].first) k++;
            counts[nums[i].second] += k - mid;

            while (j < right && nums[j].first < nums[i].first) {
                temp.push_back(nums[j++]);
            }

            temp.push_back(nums[i]);
        }

        while (j < right) temp.push_back(nums[j++]);

        for (int i = left; i < right; ++i) {
            nums[i] = temp[i - left];
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> numWithIndex;
        for (int i = 0; i < n; ++i)
            numWithIndex.push_back({nums[i], i});

        vector<int> counts(n, 0);
        mergeSort(numWithIndex, counts, 0, n);
        return counts;
    }
};


// Auto-commit update
