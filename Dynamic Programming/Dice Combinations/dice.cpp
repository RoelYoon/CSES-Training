#include <iostream>
#define M (int)(1e9+7)
using namespace std;
int DP[1000005]{};
int count(int x){
    if(x<0)
        return 0;
    if(x==0)
        return 1;
    if(DP[x])
        return DP[x];
    int ways = 0;
    for(int i = 1; i<7; ++i)
        ways=(ways+(count(x-i))%M)%M;
    return DP[x]=(ways%M);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    cout<<count(n)<<"\n";
}