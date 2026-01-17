#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,t; cin>>n>>t;
    vector<int> nums(n);
    unordered_map<int,vector<int>> set;
    set.reserve(500000);
    for(int i = 0; i < n; ++i){
        cin>>nums[i];
        if(set.find(nums[i])==set.end()){
            set.insert({nums[i],vector<int>{i}});
        }else{
            set[nums[i]].push_back(i);
        }
    }
    for(int i = 0; i < n; ++i){
        unordered_map<int,vector<int>>::iterator it = set.find(t-nums[i]);
        if(it!=set.end()){
            for(int j = 0; j < it->second.size(); ++j){
                if((it->second)[j]!=i){
                    cout<<(i+1)<<" "<<((it->second)[j]+1)<<"\n";
                    return 0;
                }
            }
        }
    }
    cout<<"IMPOSSIBLE\n";
}