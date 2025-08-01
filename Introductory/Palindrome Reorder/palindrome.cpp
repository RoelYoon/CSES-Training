#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int freq[91]{};
    string s; cin>>s;
    for(int i = 0; i < s.size(); ++i)
        ++freq[s[i]];
    string ans="";
    int loneID=-1;
    for(int i = 65; i<91; ++i){
        if(freq[i]%2){
            if(loneID>0 || !(s.size()%2)){
                cout<<"NO SOLUTION\n";
                return 0;
            }
            loneID=i;
        }else{
            ans+=string(freq[i]/2,(char)i);
        }
    }
    string reverseAns(ans);
    reverse(reverseAns.begin(),reverseAns.end());
    ans=ans+string(freq[loneID],(char)loneID)+reverseAns;
    cout<<ans<<"\n";
}