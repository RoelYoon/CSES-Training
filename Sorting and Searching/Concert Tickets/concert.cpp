#include <iostream>
#include <map>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin>>n>>m;
    map<int,int> prices;
    for(int i = 0; i < n; ++i){
        int x; cin>>x;
        if(prices.find(x)==prices.end()){
            prices.insert({x,1});
        }else{
            prices[x]+=1;
        }
    }
    for(int i = 0; i < m; ++i){
        int x; cin>>x;
        if(prices.empty()){
            cout<<"-1\n";
            continue;
        }
        map<int,int>::iterator it = prices.lower_bound(x);
        if(it==prices.end()){
            --it;
        }else if(it->first>x){
            if(it==prices.begin()){
                cout<<"-1\n";
                continue;
            }
            --it;
        }
        cout<<it->first<<"\n";
        if(--(it->second)==0){
            prices.erase(it);
        }
    }
}