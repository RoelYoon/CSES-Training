#include <iostream>
using namespace std;
int n;
void print(int &code){
    for(int i = n-1; i >= 0; --i)
        cout<<(code&(1<<i)?1:0);
    cout<<"\n";
}
int incDigit(int &code){
    for(int i = 0; i < 32; ++i)
        if(!(code&(1<<i)))
            return i;
    return -1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int turn=0,code=0;
    for(int i = 0; i < (1<<n); ++i){
        print(code);
        code^=(1<<incDigit(turn));
        ++turn;
    }
}