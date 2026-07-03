#include <iostream>
#include <vector>
#include <unordered_map>
#define MAX_N (200000)
using namespace std;
unordered_map<int, int> pos;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    pos.reserve(MAX_N);
    int ans = 1;
    int j = 0;
    for(int i = 0; i < n; ++i){
        int x; cin>>x;
        unordered_map<int,int>::iterator it = pos.find(x);
        if(it!=pos.end() && j <= it->second){
            j = it->second+1;
        }
        ans = max(ans, i-j+1);
        pos[x] = i;
    }
    cout<<ans<<"\n";
}
