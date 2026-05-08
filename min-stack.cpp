// Problem  : Min Stack
// Difficulty: Medium
// Tags     : Stack, Design
// URL      : https://leetcode.com/problems/min-stack/
// Solved on: 2026-04-09 00:17
// ──────────────────────────────────────────────────

class MinStack {
private:
    std::stack<int> st;
    std::stack<int> minSt;

public:
    MinStack() {
        // constructor does nothing initially
    }

    void push(int val) {
        st.push(val);
        // if min stack is empty or new val <= current min, push to min stack
        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }

    void pop() {
        if (st.top() == minSt.top()) {
            minSt.pop();
        }
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};


// Auto-commit update
