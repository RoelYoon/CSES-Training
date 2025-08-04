#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q; cin>>q;
    ll tpow[19]{1};
    for(int i = 1; i <= 18; ++i){
        tpow[i]=tpow[i-1]*10;
    }
    while(q--){
        ll k; cin>>k;
        for(ll i = 1; i<=18; ++i){
            ll low=0,high=9*tpow[i-1];
            while(low<high){
                ll mid=low+(high-low)/2;
                if(mid*i<k){
                    low=mid+1;
                }else if(mid*i>k){
                    high=mid;
                }else{
                    low=high=mid;
                }
            }
            k-=i*low;
            if(k<0){
                --low;
                k+=i;
            }
            if(k<i){
                ll num = (i!=1?tpow[i-1]:0)+low+(!k&&i!=1?-1:0);
                string numS = to_string(num);
                cout<<numS[(!k?i-1:(k-1))]<<"\n";
                break;
            }
        }
    }
}