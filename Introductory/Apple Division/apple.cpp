#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#define ll long long
using namespace std;
ll ans = 1e18,sum=0;
unordered_set<ll> seen;
void generate(vector<ll> &nums, int &used, ll cur){
    if(seen.find(cur)!=seen.end())
        return;
    seen.insert(cur);
    ans=min(ans,abs((sum-cur)-cur));
    for(int i = 0; i < nums.size(); ++i){
        if(used&(1<<i)) continue;
        used|=(1<<i);
        generate(nums,used,cur+nums[i]);
        used^=(1<<i);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    vector<ll> nums(n);
    for(int i = 0; i < n; ++i){
        cin>>nums[i];
        sum+=nums[i];
    }
    int used=0;
    generate(nums,used,0);
    cout<<ans<<"\n";
}