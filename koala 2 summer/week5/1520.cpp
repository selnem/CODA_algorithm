#include<iostream>
#include<string.h>
using namespace std;

const int dr[4]={0,1,-1,0};
const int dc[4]={1,0,0,-1};
int DP[500][500];
int mapp[500][500];
int R,C;

int downhillDP(int r,int c);
inline bool inRange(int r,int c);

int main(){
    cin>>R>>C;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>mapp[i][j];
        }
    }
    memset(DP,-1,sizeof(DP));
    cout<<downhillDP(0,0);

    return 0;
}

inline bool inRange(int r,int c){
    return 0<=r&&r<R&&0<=c&&c<C;
}

int downhillDP(int r,int c){
    if(r==R-1&&c==C-1) return 1;
    if(DP[r][c]!=-1) return DP[r][c];
    DP[r][c]=0;
    for(int i=0;i<4;i++){
        int nr=r+dr[i];
        int nc=c+dc[i];
        if(!inRange(nr,nc)) continue;
        if(mapp[r][c]<=mapp[nr][nc]) continue;
        DP[r][c]+=downhillDP(nr,nc);
    }
    return DP[r][c];
}