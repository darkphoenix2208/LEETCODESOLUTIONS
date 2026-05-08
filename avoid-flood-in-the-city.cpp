// Problem  : Avoid Flood in The City
// Difficulty: Medium
// Tags     : Array, Hash Table, Binary Search, Greedy, Heap (Priority Queue)
// URL      : https://leetcode.com/problems/avoid-flood-in-the-city/
// Solved on: 2026-04-09 00:09
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        unordered_map<int, int> lakeLastRain; 
        set<int> dryDays;
        vector<int> res(n, 1);

        for (int i = 0; i < n; ++i) {
            if (rains[i] > 0) {
                int lake = rains[i];
                if (lakeLastRain.count(lake)) {
                    
                    auto it = dryDays.lower_bound(lakeLastRain[lake] + 1);
                    if (it == dryDays.end()) {

                        return {};
                    }
                    res[*it] = lake; 
                    dryDays.erase(it); 
                }
                lakeLastRain[lake] = i; 
                res[i] = -1;
            } else {
                
                dryDays.insert(i);
                
            }
        }

        return res;
    }
};


// Auto-commit update
