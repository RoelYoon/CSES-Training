#include <iostream>
#define ll long long
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        ll a,b; cin>>a>>b;
        if(b-2*a > 0 || abs(b-2*a)%3){
            cout<<"NO\n";
            continue;
        }
        ll x = (abs(b-2*a)/3);
        if(a-2*x < 0){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
    }
}