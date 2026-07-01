#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    unordered_map<int,int> pos;
    vector<int> nums;
    int n,m; cin>>n>>m;
    for(int i = 0; i < n; ++i){
        int x; cin>>x;
        pos.insert({x,i});
        nums.push_back(x);
    }
    pos.insert({0,n});
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        unordered_map<int,int>::iterator it = pos.find(i);
        if(pos.find(i-1)->second > it->second){
            ++ans;
        }
    }
    for(int i = 0; i < m; ++i){
        int a,b; cin>>a>>b;
        unordered_map<int,int>::iterator ait = pos.find(nums[a-1]), bit = pos.find(nums[b-1]);
        int tmp = ait->second;
        unordered_map<int,int>::iterator it = pos.find(nums[a-1]-1), it2 = pos.find(nums[a-1]+1);
        if(it!=pos.end() && it->second > ait->second){
            --ans;
        }
        if(it2!=pos.end() && ait->second > it2->second){
            --ans;
        }
        ait->second = bit->second;
        if(it!=pos.end() && it->second > ait->second){
            ++ans;
        }
        if(it2!=pos.end() && ait->second > it2->second){
            ++ans;
        }
        it = pos.find(nums[b-1]-1), it2=pos.find(nums[b-1]+1);
        if(it!=pos.end() && it->second > bit->second){
            --ans;
        }
        if(it2!=pos.end() && bit->second > it2->second){
            --ans;
        }
        bit->second = tmp;
        if(it!=pos.end() && it->second > bit->second){
            ++ans;
        }
        if(it2!=pos.end() && bit->second > it2->second){
            ++ans;
        }
        tmp = nums[a-1];
        nums[a-1] = nums[b-1];
        nums[b-1] = tmp;
        cout<<ans<<"\n";
    }
}
