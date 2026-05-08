// Problem  : Implement Stack using Queues
// Difficulty: Easy
// Tags     : Stack, Design, Queue
// URL      : https://leetcode.com/problems/implement-stack-using-queues/
// Solved on: 2026-04-09 00:10
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>
using namespace std;

class MyStack {
    queue<int> q;
public:
    MyStack() { }

    void push(int x) {
        q.push(x);

        int sz = q.size();
        while (sz > 1) {
            q.push(q.front());
            q.pop();
            sz--;
        }
    }

    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};


// Auto-commit update
