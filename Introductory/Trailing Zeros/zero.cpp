#include <iostream>
using namespace std;
int pow5[13]{1,5,25,125,625,3125,15625,78125,390625,1953125,9765625,48828125,244140625};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    int ans = 0;
    for(int i = 12; i>0; --i)
        ans+=(n/pow5[i]);
    cout<<ans<<"\n";
}