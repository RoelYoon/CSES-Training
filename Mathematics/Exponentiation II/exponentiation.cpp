#include <iostream>
#define ll long long
using namespace std;
ll modPow(ll a, ll b, ll M){
    ll res = 1;
    while(b){
        if(b&1){
            res=(res*a)%M;
        }
        a=(a*a)%M;
        b>>=1;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    const ll M = ((ll)1e9)+7;
    int n; cin>>n;
    for(int i = 0; i < n; ++i){
        ll a,b,c; cin>>a>>b>>c;
        cout<<modPow(a,modPow(b,c,M-1),M)<<"\n";
    }
}