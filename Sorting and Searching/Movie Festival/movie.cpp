#include <iostream>
#include <vector>
#include <algorithm>
struct Movie{
    int a,b;
    Movie(){}
    Movie(int a, int b):a(a),b(b){}
};
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    vector<Movie> movies(n);
    for(int i = 0; i < n; ++i){
        cin>>movies[i].a>>movies[i].b;
    }
    sort(movies.begin(),movies.end(),[](const Movie &a, const Movie &b){
        return a.b<b.b;
    });
    int time = 0;
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        if(movies[i].a>=time){
            ++cnt;
            time=movies[i].b;
        }
    }
    cout<<cnt<<"\n";
}