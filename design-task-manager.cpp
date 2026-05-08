// Problem  : Design Task Manager
// Difficulty: Medium
// Tags     : Hash Table, Design, Heap (Priority Queue), Ordered Set
// URL      : https://leetcode.com/problems/design-task-manager/
// Solved on: 2026-04-09 00:11
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>
using namespace std;

class TaskManager {
    struct Entry {
        long long priority;
        long long taskId;
        long long userId;
        bool operator<(const Entry &other) const {
            if (priority == other.priority) return taskId < other.taskId;
            return priority < other.priority;
        }
    };

    unordered_map<long long, pair<long long,long long>> taskInfo;
    priority_queue<Entry> pq;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            int user = t[0], task = t[1], pr = t[2];
            taskInfo[task] = {user, pr};
            pq.push({pr, task, user});
        }
    }

    void add(int userId, int taskId, int priority) {
        taskInfo[taskId] = {userId, priority};
        pq.push({priority, taskId, userId});
    }

    void edit(int taskId, int newPriority) {
        auto [user, oldPr] = taskInfo[taskId];
        taskInfo[taskId] = {user, newPriority};
        pq.push({newPriority, taskId, user});
    }

    void rmv(int taskId) {
        taskInfo.erase(taskId);
    }

    int execTop() {
        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
    
            auto it = taskInfo.find(top.taskId);
            if (it != taskInfo.end()
                && it->second.second == top.priority   
                && it->second.first  == top.userId) {  
                int user = (int) top.userId;
                taskInfo.erase(top.taskId);
                return user;
            }
          
        }
        return -1;
    }
};


// Auto-commit update
