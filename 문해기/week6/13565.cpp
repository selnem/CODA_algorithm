#include<iostream>
#include<queue>
using namespace std;

typedef pair<int,int> pp;
const int dr[4]={0,1,0,-1};
const int dc[4]={1,0,-1,0};

char mapp[1000][1000]={0};
bool vis[1000][1000]={0};
int n,m;
inline bool inrange(int r,int c);
bool bfs(int a, int b);
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char tmp;
            cin>>tmp;
            mapp[i][j]=tmp;
        }
    }
    for(int i=0;i<m;i++){
        if(mapp[0][i]=='1') continue;
        if(vis[0][i]) continue;
        if(bfs(0,i)){
            cout<<"YES";
            return 0;
        } 
    }
    cout<<"NO";

    return 0;
}

bool bfs(int a, int b){
    queue<pp> q;
    q.push({a,b});
    int r,c;
    while(!q.empty()){
        pp tmp=q.front();
        r=tmp.first;
        c=tmp.second;
        q.pop();
        vis[r][c]=true;
        for(int i=0;i<4;i++){
            int nr=r+dr[i],nc=c+dc[i];
            if(!inrange(nr,nc)) continue;
            if(vis[nr][nc]) continue;
            if(mapp[nr][nc]=='1') continue;
            q.push({nr,nc});
            vis[nr][nc]=true;
            if(nr==n-1) return true;
        }
    }
    return false;
}


inline bool inrange(int r, int c){
    return 0<=r&&r<n&&0<=c&&c<m;
}