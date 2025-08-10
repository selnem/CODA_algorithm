#include<iostream>
#include<vector>
using namespace std;

const int dr[4]={0,1,-1,0};
const int dc[4]={-1,0,0,1};

int mapp[500][500];
int dp[500][500]={0};
int N;
inline bool inRange(int r,int c);
int pandaDP(int r,int c);

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>mapp[i][j];
        }
    }
    int ans=-1;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            ans=max(ans,pandaDP(i,j));
        }
    }
    cout<<ans;
    return 0;
}

int pandaDP(int r,int c){
    if(r>=N||c>=N) return 0;
    if(dp[r][c]) return dp[r][c];
    dp[r][c]=1;
    for(int i=0;i<4;i++){
        int nr=r+dr[i];
        int nc=c+dc[i];
        if(!inRange(nr,nc)) continue;
        if(mapp[r][c]>=mapp[nr][nc]) continue;
        dp[r][c]=max(dp[r][c],pandaDP(nr,nc)+1);
    }
    return dp[r][c];
}
inline bool inRange(int r,int c){
    return 0<=r&&r<N&&0<=c&&c<N;
}