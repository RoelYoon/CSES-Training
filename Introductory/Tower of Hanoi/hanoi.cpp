#include <iostream>
using namespace std;
int hanoiCount(int n){
    if(n==1) return 1;
    return 2*hanoiCount(n-1)+1;
}
void printHanoiSequence(int n, int start, int target){
    if(n==1){
        cout<<start<<" "<<target<<"\n";
        return;
    }
    int support = 6-start-target;
    printHanoiSequence(n-1,start,support);
    cout<<start<<" "<<target<<"\n";
    printHanoiSequence(n-1,support,target);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    cout<<hanoiCount(n)<<"\n";
    printHanoiSequence(n,1,3);
}