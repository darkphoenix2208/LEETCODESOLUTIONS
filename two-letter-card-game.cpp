// Problem  : Two-Letter Card Game
// Difficulty: Medium
// Tags     : Array, Hash Table, String, Counting, Enumeration
// URL      : https://leetcode.com/problems/two-letter-card-game/
// Solved on: 2026-04-09 00:14
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int score(vector<string>& cards, char key) {
    
        vector<int> leftCount(26, 0), rightCount(26, 0);
        int doubles = 0;
        for (auto &c : cards) {
            char u = c[0], v = c[1];
            if (u == key && v == key) {
                ++doubles;
            } else if (u == key) {
                leftCount[v - 'a']++;
            } else if (v == key) {
                rightCount[u - 'a']++;
            }
        }
        vector<int> leftGroups, rightGroups;
        int totalLeft = 0, totalRight = 0;
        for (int i = 0; i < 26; i++) {
            if (i == key - 'a') continue;
            if (leftCount[i] > 0) {
                leftGroups.push_back(leftCount[i]);
                totalLeft += leftCount[i];
            }
            if (rightCount[i] > 0) {
                rightGroups.push_back(rightCount[i]);
                totalRight += rightCount[i];
            }
        }

        auto maxPairs = [&](vector<int> groups, int removals) {
            if (groups.empty()) return 0;
            sort(groups.rbegin(), groups.rend());
            int n = groups.size();
            int idx = 0;

            while (removals > 0 && idx < n) {
                int next = (idx + 1 < n ? groups[idx + 1] : 0);
                long long need = 1LL * (groups[idx] - next) * (idx + 1);
                if (need <= 0) { idx++; continue; }
                if (removals >= need) {
                    for (int j = 0; j <= idx; j++) groups[j] = next;
                    removals -= (int)need;
                    idx++;
                } else {
                    int q = removals / (idx + 1);
                    int r = removals % (idx + 1);
                    for (int j = 0; j <= idx; j++) groups[j] -= q;
                    for (int j = 0; j < r; j++) groups[j]--;
                    removals = 0;
                }
            }

            if (removals > 0 && !groups.empty()) {
                int q = removals / groups.size();
                int r = removals % groups.size();
                for (int j = 0; j < (int)groups.size(); j++) groups[j] = max(0, groups[j] - q);
                for (int j = 0; j < r; j++) groups[j] = max(0, groups[j] - 1);
            }

            int sum = 0, mx = 0;
            for (int v : groups) { sum += v; mx = max(mx, v); }
            return (sum == 0 ? 0 : min(sum / 2, sum - mx));
        };
        int maxBUse = min(doubles, totalRight);
        vector<int> bestRight(maxBUse + 1), prefix(bestRight.size(), 0);
        for (int take = 0; take <= maxBUse; take++) {
            bestRight[take] = maxPairs(rightGroups, take) + take;
        }
        int cur = 0;
        for (int i = 0; i < (int)bestRight.size(); i++) {
            cur = max(cur, bestRight[i]);
            prefix[i] = cur;
        }
        int answer = 0;
        int maxAUse = min(doubles, totalLeft);
        for (int take = 0; take <= maxAUse; take++) {
            int leftPairs = maxPairs(leftGroups, take);
            int remaining = doubles - take;
            int rightBest = prefix[min(remaining, totalRight)];
            answer = max(answer, leftPairs + take + rightBest);
        }

        return answer;
    }
};


// Auto-commit update
