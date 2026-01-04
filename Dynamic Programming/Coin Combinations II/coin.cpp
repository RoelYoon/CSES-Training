#include <iostream>
#define ll long long 
#define MAX_X 1000000
#define M ((int)1e9+7)
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; ll x;
    cin>>n>>x;
    ll coins[100];
    ll DP[MAX_X+1]{}; // cnt for achieving x
    for(int i = 0; i < n; ++i){
        cin>>coins[i];
    }
    DP[0]=1;
    for(int i = 0; i < n; ++i){
        for(int j = coins[i]; j<=x; ++j){
            int pi = j-coins[i];
            if(!DP[pi]) continue;
            DP[j]=((DP[j]%M)+(DP[j-coins[i]]%M))%M;
        }
    }
    cout<<DP[x]<<"\n";
}