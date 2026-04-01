// Problem  : Robot Collisions
// Difficulty: Hard
// Tags     : Array, Stack, Sorting, Simulation
// URL      : https://leetcode.com/problems/robot-collisions/
// Solved on: 2026-05-08 21:49
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& p, vector<int>& h, string d) {
        int n=p.size();

        vector<pair<int,int>> a;

        for(int i=0;i<n;i++){
            a.push_back({p[i],i});
        }

        sort(a.begin(),a.end());

        stack<int> s;

        vector<int> alive(n,1);

        for(auto x:a){
            int i=x.second;

            if(d[i]=='R'){
                s.push(i);
            }
            else{
                while(!s.empty() && h[i]>0){
                    int j=s.top();

                    if(h[j]<h[i]){
                        s.pop();
                        alive[j]=0;
                        h[i]--;
                    }
                    else if(h[j]>h[i]){
                        h[j]--;
                        alive[i]=0;
                        h[i]=0;
                    }
                    else{
                        s.pop();
                        alive[j]=0;
                        alive[i]=0;
                        h[i]=0;
                    }
                }
            }
        }

        vector<int> ans;

        for(int i=0;i<n;i++){
            if(alive[i] && h[i]>0){
                ans.push_back(h[i]);
            }
        }

        return ans;
    }
};

// Auto-commit update
