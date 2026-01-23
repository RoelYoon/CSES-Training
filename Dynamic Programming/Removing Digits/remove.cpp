#include <iostream>
#define MAX 1000000
#define INF ((int)1e9)
using namespace std;
int DP[MAX+1];
int minSteps(int n){
    if(n<0)
        return INF;
    if(n==0)
        return 0;
    if(DP[n]!=-1)
        return DP[n];
    int x = n;
    int res = INF;
    while(x){
        if(x%10!=0)
            res=min(res,minSteps(n-x%10));
        x/=10;
    }
    return DP[n]=(res+1);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    for(int i = 0; i <= n; ++i)
        DP[i]=-1;
    cout<<minSteps(n)<<"\n";
}