#include <iostream>
#define ll long long
#define M (ll)(1e9+7)
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n; cin>>n;
    ll ans = 1;
    for(int i = 0; i < n; ++i)
        ans=(ans*2)%M;
    cout<<ans<<"\n";
}