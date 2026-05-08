// Problem  : Asteroid Collision
// Difficulty: Medium
// Tags     : Array, Stack, Simulation
// URL      : https://leetcode.com/problems/asteroid-collision/
// Solved on: 2026-04-09 00:17
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        std::stack<int> st;

        for (int i = 0; i < a.size(); i++) {
            bool destroyed = false;

            while (!st.empty() && a[i] < 0 && st.top() > 0) {
                if (st.top() < abs(a[i])) {
                    st.pop();  // smaller one destroyed
                } else if (st.top() == abs(a[i])) {
                    st.pop();  // both destroyed
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;  // incoming one destroyed
                    break;
                }
            }

            if (!destroyed) {
                st.push(a[i]);
            }
        }

        // Convert stack to vector
        vector<int> res(st.size());
        for (int i = st.size() - 1; i >= 0; --i) {
            res[i] = st.top();
            st.pop();
        }

        return res;
    }
};


// Auto-commit update
