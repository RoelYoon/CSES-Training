#include <iostream>
#define ll long long
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        ll r,c; cin>>r>>c;
        ll dom=max(r,c);
        bool isRowDom=r>c;
        if(dom%2){
            if(isRowDom){
                cout<<(dom-1)*(dom-1)+c<<"\n";
            }else{
                cout<<(dom-1)*(dom-1)+dom+(dom-r)<<"\n";
            }
        }else{
            if(!isRowDom){
                cout<<(dom-1)*(dom-1)+r<<"\n";
            }else{
                cout<<(dom-1)*(dom-1)+dom+(dom-c)<<"\n";
            }
        }
    }
}