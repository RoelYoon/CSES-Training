#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node{
    int r,c;
    Node(){}
    Node(int r, int c):r(r),c(c){}
};
struct State{
    Node node;
    int move;
    State(){}
    State(Node node, int m):node(node.r,node.c),move(m){}
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    vector<vector<vector<Node>>> graph(n,vector<vector<Node>>(n));
    for(int r=0; r<n; ++r){
        for(int c=0; c<n; ++c){
            for(int i=1; i<=2; ++i){
                for(int j=1; j<=2; ++j){
                    if(i==j) continue;
                    for(int k=-1; k<=1; k+=2){
                        for(int k2=-1; k2<=1; k2+=2){
                            int nr=r+i*k,nc=c+j*k2;
                            if(nr>=0 && nr<n && nc>=0 && nc<n){
                                graph[r][c].emplace_back(nr,nc);
                            }
                        }
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(n,vector<int>(n));
    vector<vector<bool>> visited(n,vector<bool>(n));
    queue<State> q;
    q.emplace(Node(0,0),0);
    visited[0][0]=1;
    while(!q.empty()){
        State state = q.front(); q.pop();
        Node &head=state.node;
        ans[head.r][head.c]=state.move;
        for(int i = 0; i < graph[head.r][head.c].size(); ++i){
            Node &next = graph[head.r][head.c][i];
            if(!visited[next.r][next.c]){
                visited[next.r][next.c]=1;
                q.push(State(next,state.move+1));
            }
        }
    }
    for(int r=0; r<n; ++r){
        for(int c=0; c<n; ++c){
            cout<<ans[r][c]<<" ";
        }cout<<"\n";
    }cout<<"\n";
}