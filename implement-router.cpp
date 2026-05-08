// Problem  : Implement Router
// Difficulty: Medium
// Tags     : Array, Hash Table, Binary Search, Design, Queue, Ordered Set
// URL      : https://leetcode.com/problems/implement-router/
// Solved on: 2026-04-09 00:11
// ──────────────────────────────────────────────────

class Router {
    struct Packet {
        int source;
        int destination;
        int timestamp;
    };

    int memoryLimit;
    deque<Packet> q;
    unordered_set<string> seen;
    unordered_map<int, vector<int>> destMap;

    string makeKey(int source, int destination, int timestamp) {
        return to_string(source) + "," + to_string(destination) + "," + to_string(timestamp);
    }

public:
    Router(int memoryLimit) : memoryLimit(memoryLimit) {}

    bool addPacket(int source, int destination, int timestamp) {
        string key = makeKey(source, destination, timestamp);
        if (seen.count(key)) return false;

        if ((int)q.size() == memoryLimit) {
            Packet old = q.front(); q.pop_front();
            string oldKey = makeKey(old.source, old.destination, old.timestamp);
            seen.erase(oldKey);
            
            auto& vec = destMap[old.destination];
            auto it = lower_bound(vec.begin(), vec.end(), old.timestamp);
            if (it != vec.end() && *it == old.timestamp) vec.erase(it);
            if (vec.empty()) destMap.erase(old.destination);
        }

        q.push_back({source, destination, timestamp});
        seen.insert(key);
        destMap[destination].push_back(timestamp);  
        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty()) return {};
        Packet p = q.front(); q.pop_front();
        string key = makeKey(p.source, p.destination, p.timestamp);
        seen.erase(key);

        auto& vec = destMap[p.destination];
        auto it = lower_bound(vec.begin(), vec.end(), p.timestamp);
        if (it != vec.end() && *it == p.timestamp) vec.erase(it);
        if (vec.empty()) destMap.erase(p.destination);

        return {p.source, p.destination, p.timestamp};
    }

    int getCount(int destination, int startTime, int endTime) {
        if (!destMap.count(destination)) return 0;
        auto& vec = destMap[destination];
        auto low = lower_bound(vec.begin(), vec.end(), startTime);
        auto high = upper_bound(vec.begin(), vec.end(), endTime);
        return high - low;
    }
};


// Auto-commit update
