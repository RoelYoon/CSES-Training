#include <iostream>
#include <vector>
#define ll long long
using namespace std;
bool used[1000001]{};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n; cin>>n;
    ll sum=n*(n+1)/2;
    if(sum%2){
        cout<<"NO\n";
        return 0;
    }
    sum/=2;
    cout<<"YES\n";
    vector<int> usedNum;
    for(int i=n; i>0; --i){
        if(sum>=i){
            used[i]=1;
            usedNum.push_back(i);
            sum-=i;
        }
    }
    cout<<usedNum.size()<<"\n";
    for(int i = 0; i < usedNum.size(); ++i)
        cout<<usedNum[i]<<" ";
    cout<<"\n";
    cout<<n-usedNum.size()<<"\n";
    for(int i = 1; i <= n; ++i)
        if(!used[i])
            cout<<i<<" ";
    cout<<"\n";
}