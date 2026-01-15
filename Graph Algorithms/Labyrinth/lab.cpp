#include <iostream>
#include <vector>
#include <complex>
#include <queue>
#include <algorithm>
#define pt complex<int>
#define ROW real()
#define COL imag()
using namespace std;
int R,C;
const pt dir[4]{pt(0,1),pt(1,0),pt(0,-1),pt(-1,0)};
void makePath(string &s, vector<vector<pt>> &visited, pt head){
    pt p = visited[head.ROW][head.COL];
    if(p==head){
        return;
    }
    if(p-head == dir[0]){
        s.push_back('L');
    }else if(p-head==dir[1]){
        s.push_back('U');
    }else if(p-head==dir[2]){
        s.push_back('R');
    }else{
        s.push_back('D');
    }
    makePath(s,visited,p);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>R>>C;
    pt A,B;
    vector<string> grid(R);
    for(int r= 0; r <R ; ++r){
        string s; cin>>s;
        grid[r]=s;
        for(int c= 0; c< C; ++c){
            if(s[c]=='A'){
                A=pt(r,c);
            }else if(s[c]=='B'){
                B=pt(r,c);
            }
        }
    }
    vector<vector<pt>> visited(R,vector<pt>(C,pt(-1,-1)));
    queue<pt> q;
    visited[A.ROW][A.COL]=A;
    q.push(A);
    while(!q.empty()){
        pt head = q.front(); q.pop();
        if(head==B)
            break;
        for(int i = 0; i < 4; ++i){
            pt nxt = head+dir[i];
            if(nxt.ROW >= 0 && nxt.ROW<R && nxt.COL>=0 && nxt.COL<C && 
            grid[nxt.ROW][nxt.COL]!='#' && visited[nxt.ROW][nxt.COL].ROW==-1){
                visited[nxt.ROW][nxt.COL]=head;
                q.push(nxt);
            }
        }
    }
    if(visited[B.ROW][B.COL]==pt(-1,-1)){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    string path = "";
    makePath(path,visited,B);
    reverse(path.begin(),path.end());
    cout<<path.size()<<"\n"<<path<<"\n";
}