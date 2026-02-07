#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    ll a[200000];
    for(int i = 0; i < n; ++i)
        cin>>a[i];
    sort(a,a+n);
    long long sum = 0;
    for(int i = 0; i < n; ++i){
        if(a[i]>sum+1){
            cout<<sum+1<<"\n";
            return 0;
        }
        sum+=a[i];
    }
    cout<<sum+1<<"\n";
}