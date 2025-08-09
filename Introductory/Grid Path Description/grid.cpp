#include <iostream>
#include <complex>
#define X real()
#define Y imag()
#define pt complex<int>
using namespace std;
string path;
int cnt = 0;
const pt dir[4]{{0,1},{1,0},{0,-1},{-1,0}};
bool visited[7][7]{};
inline int char2Dir(char &c){
    switch(c){
        case 'R':
            return 0;
        case 'D':
            return 1;
        case 'L':
            return 2;
        case 'U':
            return 3;
        default:
            return -1;
    }
}
inline bool isDeadEnd(pt p){
    if(p==pt(6,0) || p.X<0 || p.X>6 || p.Y<0 || p.Y>6 || visited[p.X][p.Y]){return 0;}
    int blocked = (p.X-1<0 || visited[p.X-1][p.Y]) + (p.X+1>6 || visited[p.X+1][p.Y]) + (p.Y-1<0 || visited[p.X][p.Y-1]) + (p.Y+1>6 || visited[p.X][p.Y+1]);
    return blocked==3;
}
void DFS(int m, int lastDir, pt &p){
    if(p.X<0 || p.X>6 || p.Y<0 || p.Y>6 || abs(p.X-6) + abs(p.Y-0)>48-m || m<48 && p==pt(6,0) || visited[p.X][p.Y]){
        return;
    }
    if(m==48){
        cnt+=(p==pt(6,0));
        return;
    }
    //corridor check
    if((p.Y-1<0 || visited[p.X][p.Y-1]) && (p.Y+1>6 || visited[p.X][p.Y+1])){
        // L&R blocked
        if(p.X-1>=0 && !visited[p.X-1][p.Y] && p.X+1<7 && !visited[p.X+1][p.Y]){
            return;
        }
    }
    if((p.X-1<0 || visited[p.X-1][p.Y]) && (p.X+1>6 || visited[p.X+1][p.Y])){
        // U&D blocked
        if(p.Y-1>=0 && !visited[p.X][p.Y-1] && p.Y+1<7 && !visited[p.X][p.Y+1]){
            return;
        }
    }
    visited[p.X][p.Y]=1;
    if(path[m]=='?'){
        for(int i = 0; i < 4; ++i){
            if(i!=(lastDir^2)){
                if(isDeadEnd(p+dir[i])){
                    p+=dir[i];
                    DFS(m+1,i,p);
                    p-=dir[i];   
                    break;
                }
                p+=dir[i];
                DFS(m+1,i,p);
                p-=dir[i];
            }
        }
    }else{
        int setDir = char2Dir(path[m]);
        if(setDir!=(lastDir^2)){
            p+=dir[setDir];
            DFS(m+1,setDir,p);
            p-=dir[setDir];
        }
    }
    visited[p.X][p.Y]=0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>path;
    pt p(0,0);
    DFS(0,0,p);
    cout<<cnt<<"\n";
}