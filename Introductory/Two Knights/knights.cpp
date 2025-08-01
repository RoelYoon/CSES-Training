#include <iostream>
#define ll long long
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n; cin>>n;
    for(ll i = 1; i <= n; ++i){
        cout<<(i*i-1)*i*i/2-(4+2*(i-4)+4*(i-4)*(i-2)+4*(i-2)+6*(i-2))<<"\n";
    }
}