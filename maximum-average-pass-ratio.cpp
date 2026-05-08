// Problem  : Maximum Average Pass Ratio
// Difficulty: Medium
// Tags     : Array, Greedy, Heap (Priority Queue)
// URL      : https://leetcode.com/problems/maximum-average-pass-ratio/
// Solved on: 2026-04-09 00:14
// ──────────────────────────────────────────────────

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain = [](int p, int t) {
            return (double)(p + 1) / (t + 1) - (double)p / t;
        };
        
        priority_queue<pair<double,int>> pq;
        
        int n = classes.size();
        for (int i = 0; i < n; i++) {
            pq.push({gain(classes[i][0], classes[i][1]), i});
        }
        
        while (extraStudents--) {
            auto [g, idx] = pq.top(); pq.pop();
            classes[idx][0]++;  
            classes[idx][1]++; 
            pq.push({gain(classes[idx][0], classes[idx][1]), idx});
        }
    
        double sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (double)classes[i][0] / classes[i][1];
        }
        return sum / n;
    }
};


// Auto-commit update
