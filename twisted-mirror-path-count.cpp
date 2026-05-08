// Problem  : Twisted Mirror Path Count
// Difficulty: Medium
// Tags     : Array, Dynamic Programming, Matrix
// URL      : https://leetcode.com/problems/twisted-mirror-path-count/
// Solved on: 2026-04-09 00:14
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(vector<vector<int>>& mat) {
        const int m = (int)mat.size();
        const int n = (int)mat[0].size();
        const long long MOD = 1'000'000'007LL;
        const pair<int,int> UNVIS = {-3,-3};
        vector<vector<pair<int,int>>> memoDir0(m, vector<pair<int,int>>(n, UNVIS));
        vector<vector<pair<int,int>>> memoDir1(m, vector<pair<int,int>>(n, UNVIS));

        auto computeNext = [&](int si, int sj, int startDir) -> pair<int,int> {
            auto &mem = (startDir == 0 ? memoDir0 : memoDir1);
            if (mem[si][sj] != UNVIS) return mem[si][sj];

            int r = si, c = sj;
            int dir = startDir;
            while (true) {
                int tr = (dir == 0 ? r : r + 1);
                int tc = (dir == 0 ? c + 1 : c);
                if (tr < 0 || tr >= m || tc < 0 || tc >= n) {
                    mem[si][sj] = {-1, -1};
                    return mem[si][sj];
                }

                if (mat[tr][tc] == 0) {
                    mem[si][sj] = {tr, tc};
                    return mem[si][sj];
                }

                if (dir == 0) {
                    r = tr + 1;  
                    c = tc;
                    dir = 1;
                } else {
                    r = tr;
                    c = tc + 1; 
                    dir = 0;
                }

                if (r < 0 || r >= m || c < 0 || c >= n) {
                    mem[si][sj] = {-1, -1};
                    return mem[si][sj];
                }
                while (r >= 0 && r < m && c >= 0 && c < n && mat[r][c] == 1) {
                    if (dir == 0) {
                        r = r + 1;
                        dir = 1;
                    } else {
                        c = c + 1;
                        dir = 0;
                    }
                    if (r < 0 || r >= m || c < 0 || c >= n) {
                        mem[si][sj] = {-1, -1};
                        return mem[si][sj];
                    }
                }
                mem[si][sj] = {r, c};
                return mem[si][sj];
            }
        };
        vector<vector<long long>> ways(m, vector<long long>(n, 0));
        ways[0][0] = 1; 

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (ways[i][j] == 0) continue;
                if (i == m-1 && j == n-1) continue;

                auto p0 = computeNext(i, j, 0);
                if (p0.first != -1) {
                    ways[p0.first][p0.second] = (ways[p0.first][p0.second] + ways[i][j]) % MOD;
                }
                auto p1 = computeNext(i, j, 1);
                if (p1.first != -1) {
                    ways[p1.first][p1.second] = (ways[p1.first][p1.second] + ways[i][j]) % MOD;
                }
            }
        }

        return static_cast<int>(ways[m-1][n-1]);
    }
};


// Auto-commit update
