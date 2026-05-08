// Problem  : Greatest Sum Divisible by Three
// Difficulty: Medium
// Tags     : Array, Dynamic Programming, Greedy, Sorting
// URL      : https://leetcode.com/problems/greatest-sum-divisible-by-three/
// Solved on: 2026-04-09 00:04
// ──────────────────────────────────────────────────

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        vector<int> r1, r2;

        for (int x : nums) {
            sum += x;
            if (x % 3 == 1) r1.push_back(x);
            else if (x % 3 == 2) r2.push_back(x);
        }

        sort(r1.begin(), r1.end());
        sort(r2.begin(), r2.end());

        if (sum % 3 == 0) return sum;

        int rem = sum % 3;
        int ans = 0;

        if (rem == 1) {
            int option1 = r1.size() > 0 ? sum - r1[0] : 0;
            int option2 = r2.size() > 1 ? sum - (r2[0] + r2[1]) : 0;
            ans = max(option1, option2);
        } else { 
            int option1 = r2.size() > 0 ? sum - r2[0] : 0;
            int option2 = r1.size() > 1 ? sum - (r1[0] + r1[1]) : 0;
            ans = max(option1, option2);
        }

        return ans;
    }
};


// Auto-commit update
