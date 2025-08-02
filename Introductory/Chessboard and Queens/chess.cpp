#include <iostream>
#include <unordered_set>
using namespace std;
struct Pos{
    int r;
    int c;
    Pos(){}
    Pos(int r, int c):r(r),c(c){}
    bool operator==(const Pos &p) const {
        return p.r==r && p.c==c;
    }
};
struct State{
    bool board[8][8]{};
    State(){}
    template<class... Args>
    void set(int r, int c, int v){
        board[r][c]=v;
    }
    bool operator==(const State &s) const {
        for(int r = 0; r < 8; ++r)
            for(int c = 0; c < 8; ++c)
                if(s.board[r][c]!=board[r][c])
                    return 0;
        return 1;
    }
    struct Hash{
        size_t operator()(const State &s) const {
            size_t h = 0;
            for(int r = 0; r < 8; ++r){
                for(int c = 0; c < 8; ++c){
                    if(s.board[r][c]){
                        h ^= hash<int>()(r) + 0x9e3779b9 + (h << 6) + (h >> 2);
                        h ^= hash<int>()(c) + 0x9e3779b9 + (h << 6) + (h >> 2);
                    }
                }
            }
            return h;
        }
    };
};
int closed[8][8];
long long cnt=0;
unordered_set<State,State::Hash> found;
void change(int r, int c,int d){
    int dirR[4]{-1,1,-1,1};
    int dirC[4]{1,1,-1,-1};
    for(int i = 0; i < 4; ++i){
        int tr=r,tc=c;
        while(tr>=0 && tr<8 && tc>=0 && tc<8){
            closed[tr][tc]+=d;
            tr+=dirR[i],tc+=dirC[i];
        }
    }
}
void count(int q, int &usedR, int &usedC, State &state){
    if(found.find(state)!=found.end()){return;}
    found.insert(state);
    if(q==8){
        ++cnt;
        return;
    }
    for(int r=0; r<8; ++r){
        if(usedR&(1<<r)) continue;
        usedR|=(1<<r);
        for(int c=0; c<8; ++c){
            if(closed[r][c]) continue;
            if(usedC&(1<<c)) continue;
            usedC|=(1<<c);
            change(r,c,1);
            state.set(r,c,1);
            count(q+1,usedR,usedC,state);
            state.set(r,c,0);
            change(r,c,-1);
            usedC^=(1<<c);
        }
        usedR^=(1<<r);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int r = 0; r<8; ++r){
        string s; cin>>s;
        for(int c=0; c<8; ++c)
            closed[r][c]=(s[c]=='.'?0:1e9);
    }
    int usedR=0,usedC=0;
    State state;
    count(0,usedR,usedC,state);
    cout<<cnt<<"\n";
}