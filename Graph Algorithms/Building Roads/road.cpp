#include <iostream>
#include <vector>
using namespace std;
class UnionFind{
    int n;
    int cnt;
    vector<int> par;
    vector<int> rank;
    public:
    UnionFind(int n):n(n),cnt(n),par(n),rank(n){
        for(int i = 0; i < n; ++i)
            par[i]=i;
    }
    int find(int a){
        if(par[a]==a)
            return a;
        return par[a]=find(par[a]);
    }
    void merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a!=b){
            if(rank[a] < rank[b]){
                int t = a;
                a = b;
                b = t;
            }
            // a has greater rank
            par[b]=a;
            --cnt;
            if(rank[a]==rank[b])
                ++rank[a];
        }
    }
    int size(){
        return cnt;
    }
};
void DFS(vector<vector<int>> &graph, vector<bool> &visited, UnionFind &groups, int head){
    for(int i = 0; i < graph[head].size(); ++i){
        int nxt = graph[head][i];
        if(!visited[nxt]){
            visited[nxt]=1;
            groups.merge(head,nxt);
            DFS(graph,visited,groups,nxt);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin>>n>>m;
    vector<vector<int>> graph(n);
    for(int i = 0; i < m; ++i){
        int a,b; cin>>a>>b; 
        --a,--b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<bool> visited(n);
    UnionFind groups(n);
    for(int i = 0; i < n; ++i){
        if(groups.find(i)==i){
            visited[i]=1;
            DFS(graph,visited,groups,i);
        }
    }
    cout<<groups.size()-1<<"\n";
    int first = -1;
    for(int i = 0; i < n; ++i){
        if(groups.find(i)==i){
            if(first==-1){
                first=i+1;
            }else{
                cout<<first<<" "<<i+1<<"\n";
            }
        }
    }
}