#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000005
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; int x; cin>>n>>x;
    int DP[MAX];
    vector<int> coins(n);
    fill(DP,DP+MAX,1e9);
    DP[0]=0;
    for(int i = 0; i < n; ++i){
        cin>>coins[i];
    }
    for(int i = 1; i <= x; ++i){
        for(int j = 0; j < n; ++j){
            if(i-coins[j]<0) continue;
            DP[i]=min(DP[i],DP[i-coins[j]]+1);
        }
    }
    cout<<(DP[x]==1e9?-1:DP[x])<<"\n";
}