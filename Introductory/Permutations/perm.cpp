#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    if(n==1){
        cout<<n<<"\n";
        return 0;
    }
    if(n<4){
        cout<<"NO SOLUTION\n";
        return 0;
    }
    if(n==4){
        cout<<"3 1 4 2\n";
        return 0;
    }
    int e=1,o=1+(n/2+n%2);
    bool even=1;
    while(n--){
        if(even){
            cout<<e++<<" ";
        }else{
            cout<<o++<<" ";
        }
        even=!even;
    }cout<<"\n";
}