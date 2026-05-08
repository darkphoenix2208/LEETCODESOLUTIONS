// Problem  : Candy
// Difficulty: Hard
// Tags     : Array, Greedy
// URL      : https://leetcode.com/problems/candy/
// Solved on: 2026-04-09 00:15
// ──────────────────────────────────────────────────

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n <= 1) return n;

        int total = 1;   // first child always gets 1
        int up = 0, down = 0, peak = 0;

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {  // going uphill
                up++;
                peak = up;
                down = 0;
                total += 1 + up;  // give one more than previous
            } 
            else if (ratings[i] == ratings[i - 1]) { // flat
                up = down = peak = 0;
                total += 1;
            } 
            else {  // going downhill
                up = 0;
                down++;
                total += 1 + down - (peak >= down ? 1 : 0);
                // subtract 1 if peak already counted
            }
        }

        return total;
    }
};


// Auto-commit update
