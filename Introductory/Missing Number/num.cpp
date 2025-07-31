#include <iostream>
using namespace std;
bool found[200001]{};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    for(int i = 0; i < n-1; ++i){
        int x; cin>>x;
        found[x]=1;
    }
    for(int i = 1; i <= n; ++i)
        if(!found[i])
            cout<<i<<"\n";
}