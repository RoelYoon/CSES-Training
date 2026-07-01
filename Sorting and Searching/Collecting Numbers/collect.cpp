#include <iostream>
#include <unordered_map>
#define MAX_N 100000
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    unordered_map<int,int> pos;
    int n; cin>>n;
    for(int i = 0; i < n; ++i){
        int x; cin>>x;
        pos.insert({x,i});
    }
    int p = -1;
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        unordered_map<int,int>::iterator it = pos.find(i);
        if(it->second < p){
            ++ans;
        }
        p = it->second;
    }
    cout<<ans+1<<"\n";
}