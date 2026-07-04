#include <iostream>
#include <set>
#include <map>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x,n; cin>>x>>n;
    set<int> pos;
    map<int, int> freq;
    pos.insert(x);
    pos.insert(0);
    freq.insert({x,1});
    for(int i = 0; i < n; ++i){
        int p; cin>>p;
        set<int>::iterator it = pos.lower_bound(p);
        set<int>::iterator it2 = prev(it);
        if(!(--freq[*it - *it2])){
            freq.erase(*it - *it2);
        }
        if(freq.count(*it - p)){
            freq[*it-p]++;
        }else{
            freq.insert({*it-p,1});
        }
        if(freq.count(p-*it2)){
            freq[p-*it2]++;
        }else{
            freq.insert({p-*it2,1});
        }
        pos.insert(p); 
        cout<<freq.rbegin()->first<<(i==n-1?"\n":" ");
    }
}