#include <iostream>
#include <unordered_map>
#define ll long long
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    unordered_map<int, int> pos;
    pos.reserve(50000);
    int p = 0;
    ll ans = 0; 
    for(int i = 0; i < n; ++i){
        int x; cin>>x;
        unordered_map<int,int>::iterator it = pos.find(x);
        if(it != pos.end() && it->second+1 > p){
            p = it->second+1;
        }
        pos[x] = i;
        ans += i-p+1;
    }
    cout<<ans<<"\n";
}