#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

int mDis=0;
int pass=0;

const int dr[4]={0,1,-1,0};
const int dc[4]={1,0,0,-1};
int mapp[50][50]={0};
int N,M;
inline bool inRange(int r,int c);

void bfs(int r,int c);

int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>mapp[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(mapp[i][j]) bfs(i,j);
        }
    }
    cout<<pass;
    return 0;
}
inline bool inRange(int r, int c){
    return 0<=r&&r<N&&0<=c&&c<M;
}
void bfs(const int r,const int c){
    int dist[51][51];
    memset(dist, -1, sizeof(dist));
    queue<pair<int,int>> q;
    q.push({r,c});
    dist[r][c] = 0;
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        int dis = dist[cur.first][cur.second];

        if(!(r == cur.first && c == cur.second)){
            if(mDis < dis){
                pass = mapp[r][c] + mapp[cur.first][cur.second];
                mDis = dis;
            } else if(mDis == dis){
                pass = max(pass, mapp[r][c] + mapp[cur.first][cur.second]);
            }
        }
        
        for(int i=0;i<4;i++){
            int nr = cur.first + dr[i];
            int nc = cur.second + dc[i];
            if(!inRange(nr,nc)) continue;
            if(mapp[nr][nc] == 0) continue;
            if(dist[nr][nc] != -1) continue;
            
            dist[nr][nc] = dis + 1;
            q.push({nr,nc});
        }
    }
}
