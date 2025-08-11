#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
struct Event{
    bool is_start;
    ll time;
    Event(){}
    Event(bool s, ll t):is_start(s),time(t){}
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m; ll k; cin>>n>>m>>k;
    vector<Event> events;
    for(int i = 0; i < n ; ++i){
        ll x; cin>>x;
        events.emplace_back(1,max(0LL,x-k));
        events.emplace_back(0,x+k);
    }
    sort(events.begin(),events.end(),[](const Event &a, const Event &b){
        if(a.time==b.time){
            return a.is_start>b.is_start;
        }
        return a.time<b.time;
    });
    vector<ll> rooms(m);
    for(int i = 0; i < m; ++i){
        cin>>rooms[i];
    }
    sort(rooms.begin(),rooms.end());
    int e_i = 0, r_i = 0;
    int appQ = 0;
    int ans = 0;
    int ignore = 0;
    while(e_i<events.size() && r_i<m){
        if(events[e_i].time < rooms[r_i] || (events[e_i].time==rooms[r_i] && events[e_i].is_start)){
            //e_i selected
            if(events[e_i].is_start){
                ++appQ;
            }else{
                if(ignore==0){
                    --appQ;
                }else{
                    ignore--;
                }
            }
            ++e_i;
        }else{
            //r_i selected
            if(appQ>0){
                ++ans;
                --appQ;
                ++ignore;
            }
            ++r_i;
        }
    }
    cout<<ans<<"\n";
}