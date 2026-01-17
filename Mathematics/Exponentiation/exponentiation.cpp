#include <iostream>
#define ll long long
using namespace std;
const ll M = ((ll)1e9)+7;
ll modPow(ll a, ll b){
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
    int n; cin>>n;
    for(int i = 0; i < n; ++i){
        ll a,b; cin>>a>>b;
        cout<<modPow(a,b)<<"\n";
    }
}