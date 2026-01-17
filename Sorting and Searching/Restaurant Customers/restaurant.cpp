#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Time{
    int t; 
    bool end;
    Time(){}
    Time(int t, bool end):t(t),end(end){}
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    vector<Time> times;
    for(int i = 0; i < n; ++i){
        int a,b; cin>>a>>b;
        times.emplace_back(a,0);
        times.emplace_back(b,1);
    }
    sort(times.begin(),times.end(),[](const Time &a, const Time &b){
        if(a.t==b.t) return a.end < b.end;
        return a.t<b.t;
    });
    int cnt = 0;
    int mxCnt = 0;
    for(int i = 0; i < times.size(); ++i){
        if(times[i].end){
            --cnt;
        }else{
            ++cnt;
        }
        mxCnt=max(mxCnt,cnt);
    }
    cout<<mxCnt<<"\n";
}