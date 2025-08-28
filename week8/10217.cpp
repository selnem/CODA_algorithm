#include<iostream>
#include<queue>
#include<vector>
#include<climits>
#include<tuple>
using namespace std;
typedef tuple<int,int,int> Tup;//{dis,pos,cost}

void ans();
int dijk(int N,int M,vector<vector<Tup> > &mapp);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        ans();
    }
    return 0;
}
void ans(){
    int N,M,K;
    cin>>N>>M>>K;
    vector< vector<Tup> > mapp(N+1,vector<Tup>());
    for(int i=0;i<K;i++){
        int u,v,c,d;
        cin>>u>>v>>c>>d;
        mapp[u].push_back({d,v,c});
    }
    int ans=dijk(N,M,mapp);
    if(ans==INT_MAX) cout<<"Poor KCM"<<'\n';
    else cout<<ans<<'\n';
}
int dijk(int N,int M,vector<vector<Tup> > &mapp){
    priority_queue<Tup,vector<Tup>,greater<Tup> > pq;
    vector<vector<int> > dis(N+1,vector<int>(M+1,INT_MAX));
    dis[1][0]=0;
    pq.push({0,1,0});
    while(!pq.empty()){
        auto[curDis,pos,cost]=pq.top();
        pq.pop();
        if(dis[pos][cost]<curDis) continue;
        for(auto &it:mapp[pos]){
            auto[dDis,nPos,dCost]=it;
            int nDis=dDis+curDis;
            int nCost=dCost+cost;
            if(nCost>M) continue;
            if(dis[nPos][nCost]<=nDis) continue;
            for(int j = nCost+1; j <= M; j++){
                if(dis[nPos][j] < nDis) break;
                dis[nPos][j] = nDis;
            }
            dis[nPos][nCost]=nDis;
            pq.push({nDis,nPos,nCost});
        }
    }
    int ans=INT_MAX;
    for(int i=0;i<=M;i++){
        ans=min(ans,dis[N][i]);
    }
    return ans;
}