// Problem  : Design Movie Rental System
// Difficulty: Hard
// Tags     : Array, Hash Table, Design, Heap (Priority Queue), Ordered Set
// URL      : https://leetcode.com/problems/design-movie-rental-system/
// Solved on: 2026-04-09 00:11
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct MovieRentingSystem {
    unordered_map<int, set<pair<int,int>>> avail;
    set<tuple<int,int,int>> rented;
    unordered_map<ll,int> price;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e: entries) {
            int s = e[0], m = e[1], p = e[2];
            avail[m].insert({p,s});
            price[((ll)s<<32) | m] = p;
        }
    }
    vector<int> search(int movie) {
        vector<int> res;
        auto it = avail.find(movie);
        if (it==avail.end()) return res;
        int cnt=0;
        for (auto &pr: it->second) {
            res.push_back(pr.second);
            if (++cnt==5) break;
        }
        return res;
    }
    void rent(int shop, int movie) {
        ll k = ((ll)shop<<32) | movie;
        int p = price[k];
        avail[movie].erase({p,shop});
        rented.insert({p,shop,movie});
    }
    void drop(int shop, int movie) {
        ll k = ((ll)shop<<32) | movie;
        int p = price[k];
        rented.erase({p,shop,movie});
        avail[movie].insert({p,shop});
    }
    vector<vector<int>> report() {
        vector<vector<int>> res;
        int cnt=0;
        for (auto &t: rented) {
            int p, s, m;
            p = get<0>(t);
            s = get<1>(t);
            m = get<2>(t);
            res.push_back({s,m});
            if (++cnt==5) break;
        }
        return res;
    }
};


// Auto-commit update
