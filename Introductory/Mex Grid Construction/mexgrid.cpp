#include <iostream>
#define MAX 10000
using namespace std;
bool rowOccupied[100][MAX]{};
bool colOccupied[100][MAX]{};
int mex[100][100]{};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    for(int i = 0; i < n; ++i){
        for(int r = i; r<n; ++r){
            for(int j = 0; j < MAX; ++j){
                if(!rowOccupied[r][j] && !colOccupied[i][j]){
                    mex[r][i]=j;
                    rowOccupied[r][j]=1;
                    colOccupied[i][j]=1;
                    break;
                }
            }
        }
        for(int c=i+1; c<n; ++c){
            for(int j = 0; j < MAX; ++j){
                if(!rowOccupied[i][j] && !colOccupied[c][j]){
                    mex[i][c]=j;
                    rowOccupied[i][j]=1;
                    colOccupied[c][j]=1;
                    break;
                }
            }
        }
    }
    for(int r=0; r<n; ++r){
        for(int c=0; c<n; ++c){
            cout<<mex[r][c]<<" ";
        }cout<<"\n";
    }cout<<"\n";
}