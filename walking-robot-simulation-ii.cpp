// Problem  : Walking Robot Simulation II
// Difficulty: Medium
// Tags     : Design, Simulation
// URL      : https://leetcode.com/problems/walking-robot-simulation-ii/
// Solved on: 2026-05-08 21:49
// ──────────────────────────────────────────────────

class Robot {
public:
int w,h,p;
int x=0,y=0,d=0;

vector<string> dir={"East","North","West","South"};

Robot(int width,int height){
w=width;
h=height;
p=2*(w+h)-4;
}

void step(int num){
num%=p;

if(num==0&&x==0&&y==0){
d=3;
return;
}

while(num--){
if(d==0){
if(x+1<w) x++;
else{
d=1;
y++;
}
}
else if(d==1){
if(y+1<h) y++;
else{
d=2;
x--;
}
}
else if(d==2){
if(x-1>=0) x--;
else{
d=3;
y--;
}
}
else{
if(y-1>=0) y--;
else{
d=0;
x++;
}
}
}
}

vector<int> getPos(){
return {x,y};
}

string getDir(){
return dir[d];
}
};

// Auto-commit update
