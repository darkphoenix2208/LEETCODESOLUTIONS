// Problem  : Maximize Spanning Tree Stability with Upgrades
// Difficulty: Hard
// Tags     : Binary Search, Greedy, Union-Find, Graph Theory, Minimum Spanning Tree
// URL      : https://leetcode.com/problems/maximize-spanning-tree-stability-with-upgrades/
// Solved on: 2026-05-08 21:51
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>
using namespace std;

struct DSU{
    vector<int> p,r;
    DSU(int n){
        p.resize(n);
        r.resize(n);
        for(int i=0;i<n;i++) p[i]=i;
    }
    int find(int x){
        if(p[x]!=x) p[x]=find(p[x]);
        return p[x];
    }
    bool unite(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b) return false;
        if(r[a]<r[b]) swap(a,b);
        p[b]=a;
        if(r[a]==r[b]) r[a]++;
        return true;
    }
};

class Solution {
public:
    bool check(int n,vector<vector<int>>& edges,int k,long long x){
        DSU d(n);
        int used=0;
        int upgrades=0;

        for(auto &e:edges){
            int u=e[0],v=e[1],s=e[2],m=e[3];
            if(m){
                if(s<x) return false;
                if(!d.unite(u,v)) return false;
                used++;
            }
        }

        vector<pair<int,pair<int,int>>> good,up;

        for(auto &e:edges){
            int u=e[0],v=e[1],s=e[2],m=e[3];
            if(m) continue;

            if(s>=x) good.push_back({s,{u,v}});
            else if((long long)s*2>=x) up.push_back({s,{u,v}});
        }

        for(auto &g:good){
            if(d.unite(g.second.first,g.second.second))
                used++;
        }

        for(auto &g:up){
            if(used==n-1) break;
            if(upgrades==k) break;
            if(d.unite(g.second.first,g.second.second)){
                upgrades++;
                used++;
            }
        }

        return used==n-1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {

        long long l=0,r=2e5,ans=-1;

        while(l<=r){
            long long mid=(l+r)/2;

            if(check(n,edges,k,mid)){
                ans=mid;
                l=mid+1;
            }else r=mid-1;
        }

        return ans;
    }
};

// Auto-commit update
