#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,mx=0; cin>>n;
    long long moves=0;
    for(int i = 0; i < n; ++i){
        int x; cin>>x;
        if(x<mx)
            moves+=mx-x;
        mx=max(mx,x);
    }
    cout<<moves<<"\n";
}