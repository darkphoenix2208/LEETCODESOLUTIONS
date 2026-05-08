// Problem  : Flood Fill
// Difficulty: Easy
// Tags     : Array, Depth-First Search, Breadth-First Search, Matrix
// URL      : https://leetcode.com/problems/flood-fill/
// Solved on: 2026-04-09 00:05
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int a = image[sr][sc];
        
        if (a == color) return image;

        queue<pair<int,int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int dr = x + dx[i];
                int dc = y + dy[i];

                if (dr < 0 || dc < 0 || dr >= m || dc >= n)
                    continue;

                if (image[dr][dc] == a) {
                    image[dr][dc] = color;
                    q.push({dr, dc});
                }
            }
        }

        return image;
    }
};


// Auto-commit update
