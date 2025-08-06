#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s,ans=""; cin>>s;
    int n=s.size();
    int freq[91]{};
    for(int i = 0; i < n; ++i){
        ++freq[s[i]];
    }
    char prev = '.';
    for(int i = 0; i < n; ++i){
        int force = -1;
        int minL = -1;
        bool impossible=0;
        for(char c = 65; c < 91; ++c){
            // check if position is free or forced
            if(freq[c]==0 || c==prev){continue;}
            int window = freq[c]*2-1;
            int spaceLeft = n-i;
            if(minL==-1){
                minL=c;
            }
            if(window > spaceLeft){
                impossible=1;
                break;
            }
            if(window == spaceLeft){
                //forced
                force = c;
                break;
            }
        }
        if(impossible){
            cout<<"-1\n";
            return 0;
        }
        if(force<0){
            //no force
            freq[minL]--;
            ans+=(char)minL;
            prev=minL;
        }else{
            freq[force]--;
            ans+=(char)force;
            prev=force;
        }
    }
    cout<<ans<<"\n";
}