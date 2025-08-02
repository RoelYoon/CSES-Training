#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int R,C; cin>>R>>C;
    vector<string> grid(R);
    for(int r=0; r<R; ++r)
        cin>>grid[r];
    vector<vector<vector<bool>>> banned(R,vector<vector<bool>>(C,vector<bool>(4)));
    for(int r = 0; r <R; ++r){
        for(int c= 0; c<C; ++c){
            int nr=r+1,nc=c+1;
            banned[r][c][grid[r][c]-65]=1;
            char prev = grid[r][c];
            if(nc<C && !banned[r][c][grid[r][nc]-65]){
                grid[r][c]=grid[r][nc];
            }
            if(nr<R && !banned[r][c][grid[nr][c]-65]){
                grid[r][c]=grid[nr][c];
            }
            if(grid[r][c]==prev){
                //no change
                for(int i = 0; i < 4; ++i){
                    if(!banned[r][c][i]){
                        grid[r][c]=(char)(i+65);
                        break;
                    }
                }
                if(grid[r][c]==prev){
                    cout<<"IMPOSSIBLE\n";
                    return 0;
                }
            }
            if(nr<R)
                banned[nr][c][grid[r][c]-65]=1;
            if(nc<C)
                banned[r][nc][grid[r][c]-65]=1;
        }
    }
    for(int r =0; r<R;++r)
        cout<<grid[r]<<"\n";
}