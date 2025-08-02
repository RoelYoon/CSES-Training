#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;
string s;
unordered_set<string> found;
vector<string> ans;
void generate(string &word, int used){
    if(found.find(word)!=found.end())
        return;
    found.insert(word);
    if(word.size()==s.size()){
        ans.push_back(word);
        return;
    }
    for(int i = 0; i < s.size(); ++i){
        if(!(used&(1<<i))){
            word.push_back(s[i]);
            used|=(1<<i);
            generate(word,used);
            word.pop_back();
            used^=(1<<i);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    sort(s.begin(),s.end());
    string word="";
    int used=0;
    generate(word,used);
    cout<<ans.size()<<"\n";
    for(int i=0; i < ans.size(); ++i)
        cout<<ans[i]<<"\n";
}