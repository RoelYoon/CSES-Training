#include <iostream>
#include <complex>
#include <vector>
#define pt complex<int>
#define ROW real()
#define COL imag()
using namespace std;
int R,C;
const pt dir[4]{pt(0,1),pt(1,0),pt(0,-1),pt(-1,0)};
bool DFS(vector<string> &grid, pt head){
    if(grid[head.ROW][head.COL]=='#') return 0;
    bool res = (grid[head.ROW][head.COL]=='.');
    grid[head.ROW][head.COL]='#';
    for(int i = 0; i < 4; ++i){
        pt nxt = head+dir[i];
        if(nxt.ROW >= 0 && nxt.ROW < R && nxt.COL>=0 && nxt.COL<C)
            res|=DFS(grid,nxt);
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>R>>C;
    vector<string> grid(R);
    for(int r = 0; r<R;++r){
        string s; cin>>s;
        grid[r]=s;
    }
    int cnt = 0;
    for(int r = 0; r<R; ++r){
        for(int c=0; c<C; ++c){
            cnt+=DFS(grid,pt(r,c));
        }
    }
    cout<<cnt<<"\n";
}