#include <iostream>
#include <vector>
#include <string>
#define N (1000)
using namespace std;
int DP[N][N];
const int M = 1e9+7;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    vector<string> grid(n);
    for(int r = 0; r < n; ++r){
        cin>>grid[r];
    }
    DP[0][0] = 1;
    if(grid[0][0] == '*'){
        DP[0][0] = 0;
    }
    for(int r = 0; r < n; ++r){
        for(int c = 0; c < n; ++c){
            if(!r && !c) continue;
            if(!r){
                DP[r][c] = DP[r][c-1];
            }else if(!c){
                DP[r][c] = DP[r-1][c];
            }else{
                DP[r][c] = ((DP[r-1][c])%M + (DP[r][c-1])%M)%M;
            }
            if(grid[r][c] == '*'){
                DP[r][c] = 0;
            }
        }
    }
    cout<<DP[n-1][n-1]<<"\n";
}