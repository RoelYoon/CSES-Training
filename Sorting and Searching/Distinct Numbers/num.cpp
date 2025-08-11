#include<iostream>
#include <unordered_set>
using namespace std;
unordered_set<int> set;
int main()
{
    set.reserve(10000000);
    int n; cin>>n;
    for(int i=0; i<n ;++i){
        int x; cin>>x;
        set.insert(x);
    }
    cout<<set.size()<<"\n";
    return 0;
}