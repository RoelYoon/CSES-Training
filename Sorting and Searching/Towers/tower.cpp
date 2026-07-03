#include <iostream>
#include <map>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    map<int,int> towers;
    for(int i = 0; i < n; ++i){
        int x; cin>>x;
        if(!towers.empty() && towers.rbegin()->first > x){
            map<int,int>::iterator it = towers.lower_bound(x);
            while(it->first == x){
                ++it;
            }
            if(!(--(it->second))){
                towers.erase(it);
            }
        }
        if(towers.find(x) == towers.end()){
            towers.insert({x,1});
        }else{
            towers[x]++;
        }
    }
    int ans = 0;
    for(map<int,int>::iterator it = towers.begin(); it!=towers.end(); ++it){
        ans+=it->second;
    }
    cout<<ans<<"\n";
}
