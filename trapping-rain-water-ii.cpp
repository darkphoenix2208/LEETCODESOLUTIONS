// Problem  : Trapping Rain Water II
// Difficulty: Hard
// Tags     : Array, Breadth-First Search, Heap (Priority Queue), Matrix
// URL      : https://leetcode.com/problems/trapping-rain-water-ii/
// Solved on: 2026-04-09 00:10
// ──────────────────────────────────────────────────

#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;
        int m = heightMap.size(), n = heightMap[0].size();
        int trappedWater = 0;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            minHeap.emplace(heightMap[i][0], i, 0);
            minHeap.emplace(heightMap[i][n - 1], i, n - 1);
            visited[i][0] = visited[i][n - 1] = true;
        }

        for (int j = 1; j < n - 1; ++j) {
            minHeap.emplace(heightMap[0][j], 0, j);
            minHeap.emplace(heightMap[m - 1][j], m - 1, j);
            visited[0][j] = visited[m - 1][j] = true;
        }

        vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        while (!minHeap.empty()) {
            auto [height, x, y] = minHeap.top();
            minHeap.pop();

            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    int neighborHeight = heightMap[nx][ny];
                    trappedWater += max(0, height - neighborHeight);
                    minHeap.emplace(max(height, neighborHeight), nx, ny);
                }
            }
        }

        return trappedWater;
    }
};


// Auto-commit update
