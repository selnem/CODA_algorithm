#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
#include<climits>
using namespace std;

typedef tuple<int,int,int> Tup;
typedef vector<int> List;

const int dr[4]={0,1,-1,0};
const int dc[4]={1,0,0,-1};

inline bool inRange(int r,int c, int N);
int dijk(int n);
void prn(int n);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    while(true){
        cin>>n;
        if(n==0) break;
        prn(n);
    }
    return 0;
}

int dijk(int n){
    vector< List > mapp(n,List(n));
    vector< List > dis(n,List(n,INT_MAX));
    priority_queue<Tup,vector<Tup>,greater<Tup> > pq;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mapp[i][j];
        }
    }
    dis[0][0]=mapp[0][0];
    pq.push({mapp[0][0],0,0});
    while(!pq.empty()){
        auto[curDis,r,c]=pq.top();
        pq.pop();
        if(curDis>dis[r][c]) continue;
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];

            if(!inRange(nr,nc,n)) continue;

            int nDis=curDis+mapp[nr][nc];

            if(nDis>=dis[nr][nc]) continue;

            dis[nr][nc]=nDis;
            pq.push({nDis,nr,nc});
        }
    }
    return dis[n-1][n-1];
}
inline bool inRange(int r,int c, int N){
    return 0<=r&&r<N&&0<=c&&c<N;
}

void prn(int n){
    static int cnt=0;
    cout<<"Problem "<< (++cnt) <<": "<<dijk(n)<<'\n';
}