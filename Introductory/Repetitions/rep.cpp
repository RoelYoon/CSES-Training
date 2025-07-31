#include <iostream>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s; cin>>s;
    char type='X';
    int length = 0, maxLength=0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i]!=type){
            type=s[i];
            maxLength=max(maxLength,length);
            length=0;
        }
        length++;
    }
    cout<<max(length,maxLength)<<"\n";
}