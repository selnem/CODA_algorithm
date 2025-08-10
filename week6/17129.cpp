#include<iostream>
#include<queue>
using namespace std;
const int dr[4]={0,1,0,-1};
const int dc[4]={1,0,-1,0};
int dis[3000][3000]={0};
int vis[3000][3000]={0};
char mapp[3000][3000]={0};
int N,M;

inline bool inRange(int r,int c);
int BFS(int r,int c);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M;
    const char *ans[2]={"NIE","TAK"};
    int tr,tc;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>mapp[i][j];
            if(mapp[i][j]=='2'){
                tr=i;
                tc=j;
            }
        }
    }
    int c=BFS(tr,tc);
    if(c==0) cout<<ans[0];
    else cout<<ans[1]<<'\n'<<c;
    return 0;
}

inline bool inRange(int r,int c){
    return 0<=r&&r<N&&0<=c&&c<M;
}

int BFS(int r,int c){
    queue< pair<int,int> > q;
    vis[r][c]=true;
    q.push(make_pair(r,c));
    while(!q.empty()){
        pair<int,int> tmp=q.front();
        q.pop();
        int tr=tmp.first;
        int tc=tmp.second;
        for(int i=0;i<4;i++){
            int nr=tr+dr[i];
            int nc=tc+dc[i];
            if(!inRange(nr,nc)) continue;
            if(vis[nr][nc]) continue;
            if(mapp[nr][nc]=='1') continue;
            dis[nr][nc]=dis[tr][tc]+1;
            vis[nr][nc]=1;
            q.push(make_pair(nr,nc));
            if(mapp[nr][nc]!='0') return dis[nr][nc];   
       }
    }
    return 0;
}