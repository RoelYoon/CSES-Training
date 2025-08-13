#include <iostream>
#include <vector>
#define MAX 1000005
#define M (int)(1e9+7)
using namespace std;
vector<int> coins;
int DP[MAX]{};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x; cin>>n>>x;
    coins.resize(n);
    for(int i = 0; i < n; ++i)
        cin>>coins[i];
    DP[0]=1;
    for(int i = 1; i <= x; ++i){
        for(int j = 0; j < n; ++j){
            if(i-coins[j]<0) continue;
            DP[i]=(DP[i]+DP[i-coins[j]])%M;
        }
    }
    cout<<DP[x]<<"\n";
}