#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; ll x; cin>>n>>x;
    vector<ll> w(n);
    for(int i = 0; i < n; ++i)
        cin>>w[i];
    sort(w.begin(),w.end());
    int ans = 0;
    int j = 0;
    for(int i = n-1; i>=0 && j<=i; --i){
        j+=w[i]+w[j]<=x;
        ++ans;
    }
    cout<<ans<<"\n";
}