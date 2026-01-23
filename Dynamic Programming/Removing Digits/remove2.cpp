#include <iostream>
#define MAX 1000000
#define INF ((int)1e9)
using namespace std;
int minStep[MAX+1];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    for(int i = 0; i <= n; ++i)
        minStep[i]=INF;
    minStep[0]=0;
    for(int i = 1; i <= n; ++i){
        int x = i;
        while(x){
            minStep[i] = min(minStep[i],minStep[i-x%10]+1);
            x/=10;
        }
    }
    cout<<minStep[n]<<"\n";
}