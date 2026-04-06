// Problem  : Walking Robot Simulation
// Difficulty: Medium
// Tags     : Array, Hash Table, Simulation
// URL      : https://leetcode.com/problems/walking-robot-simulation/
// Solved on: 2026-05-08 21:49
// ──────────────────────────────────────────────────

class Solution {
public:
    int robotSim(vector<int>& c, vector<vector<int>>& o) {
        set<pair<int,int>> s;
        
        for(auto &x:o){
            s.insert({x[0],x[1]});
        }

        vector<int> dx={0,1,0,-1};
        vector<int> dy={1,0,-1,0};

        int d=0;
        int x=0,y=0;
        int a=0;

        for(auto i:c){
            if(i==-1){
                d=(d+1)%4;
            }
            else if(i==-2){
                d=(d+3)%4;
            }
            else{
                for(int j=0;j<i;j++){
                    int nx=x+dx[d];
                    int ny=y+dy[d];

                    if(s.count({nx,ny})) break;

                    x=nx;
                    y=ny;

                    a=max(a,x*x+y*y);
                }
            }
        }

        return a;
    }
};

        

// Auto-commit update
