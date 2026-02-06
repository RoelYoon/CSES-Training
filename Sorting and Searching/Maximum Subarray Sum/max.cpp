#include <iostream>
#define ll long long
#define INF ((ll)1e18)
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    ll cur; cin>>cur;
    ll mx = cur;
    for(int i = 0; i < n-1; ++i){
        ll x; cin>>x;
        if(cur+x>x){
            cur = cur+x;
        }else{
            cur = x;
        }
        mx = max(mx,cur);
    }
    cout<<mx<<"\n";
}