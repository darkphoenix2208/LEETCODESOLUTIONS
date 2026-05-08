// Problem  : Four Divisors
// Difficulty: Medium
// Tags     : Array, Math
// URL      : https://leetcode.com/problems/four-divisors/
// Solved on: 2026-04-09 00:00
// ──────────────────────────────────────────────────

class Solution {
public:
int getDivisors(int n) {
    vector<int> d;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            d.push_back(i);
            if (i != n / i)
                d.push_back(n / i);
        }
    }

    if (d.size() != 4) return 0;

    int sum = 0;
    for (int x : d) sum += x;
    return sum;
}

    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=getDivisors(nums[i]);
        }
        return ans;
    }
};

// Auto-commit update
