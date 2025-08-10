#include<iostream>
#include<queue>
#define MCNT 10
using namespace std;

struct RB{
    int Rr,Rc,Br,Bc;
    int cnt;
};
char mapp[10][10];
const int dr[4]={0,1,-1,0};
const int dc[4]={1,0,0,-1};
bool vis[10][10][10][10]={0};
int N,M;
RB move(RB balls,int dir,int &rDis,int &bDis);
int BFS(RB balls);
int main(){
    cin>>N>>M;
    RB balls;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>mapp[i][j];
            if(mapp[i][j]=='R'){
                balls.Rr=i;
                balls.Rc=j;
            }else if(mapp[i][j]=='B'){
                balls.Br=i;
                balls.Bc=j;
            }
        }
    }
    balls.cnt=0;
    cout<<BFS(balls);
    return 0;
}

int BFS(RB balls){

    queue<RB>q;
    q.push(balls);
    vis[balls.Rr][balls.Rc][balls.Br][balls.Bc]=true;
    while(!q.empty()){
        RB ball=q.front();
        q.pop();
        if(ball.cnt>=MCNT) return -1;
        
        for(int i=0;i<4;i++){
            int rDis=0,bDis=0;
            RB nBall=move(ball,i,rDis,bDis);
            
            nBall.cnt+=1;
            if(mapp[nBall.Br][nBall.Bc]=='O') continue;
            if(mapp[nBall.Rr][nBall.Rc]=='O'){
                return nBall.cnt;
            }
            if(vis[nBall.Rr][nBall.Rc][nBall.Br][nBall.Bc]) continue;
            if(nBall.Rr==nBall.Br&&nBall.Rc==nBall.Bc){
                if(rDis>bDis){
                    nBall.Rr-=dr[i];
                    nBall.Rc-=dc[i];
                }
                else{
                    nBall.Br-=dr[i];
                    nBall.Bc-=dc[i];
                }
        }
            vis[nBall.Rr][nBall.Rc][nBall.Br][nBall.Bc]=true;
            q.push(nBall);
        }
    }
    return -1;

}
RB move(RB balls,int dir,int &rDis,int &bDis){
    
    while(mapp[balls.Rr+dr[dir]][balls.Rc+dc[dir]]!='#'&&mapp[balls.Rr][balls.Rc]!='O'){
        balls.Rr+=dr[dir];
        balls.Rc+=dc[dir];
        ++rDis;
    }
    while(mapp[balls.Br+dr[dir]][balls.Bc+dc[dir]]!='#'&&mapp[balls.Br][balls.Bc]!='O'){
        balls.Br+=dr[dir];
        balls.Bc+=dc[dir];
        ++bDis;
    }
    
    return balls;

}
