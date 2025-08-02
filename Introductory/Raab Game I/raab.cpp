#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n,a,b; cin>>n>>a>>b;
        vector<int> p1(n),p2(n);
        iota(p1.begin(),p1.end(),1);
        iota(p2.begin(),p2.end(),1);
        int ties = n-(a+b);
        if(a==0 && b==0){
            cout<<"YES\n";
            for(int i = 1; i<=n; ++i)
                cout<<i<<" ";
            cout<<"\n";
            for(int i = 1; i<=n; ++i)
                cout<<i<<" ";
            cout<<"\n";
            continue;
        }
        if(ties<0 || b>=n-ties || a>=n-ties){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        for(int i = 1; i<=n; ++i)
            cout<<i<<" ";
        cout<<"\n";
        for(int i = 0; i < ties; ++i)
            cout<<p2[i]<<" ";
        for(int i = n-b; i < n; ++i)
            cout<<p2[i]<<" ";
        for(int i = ties; i < n-b; ++i)
            cout<<p2[i]<<" ";
        cout<<"\n";
    }
}