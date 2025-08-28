#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
#include<climits>
using namespace std;

typedef pair<int,int> Pr;
vector<Pr> mapp[801];

int N,M;

Pr dikj(int s,int e1,int e2);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int a,b,c;
        cin>>a>>b>>c;
        mapp[a].push_back({c,b});
        mapp[b].push_back({c,a});
    }
    int v1,v2;
    cin>>v1>>v2;

    auto [OneToV1,OneToV2]=dikj(1,v1,v2);
    auto [v1ToV2,V1ToN]=dikj(v1,v2,N);
    auto [NTOV1,NToV2]=dikj(N,v1,v2);
    int ans=-1;
    if(OneToV1!=INT_MAX&&v1ToV2!=INT_MAX&&NToV2!=INT_MAX) ans=OneToV1+v1ToV2+NToV2;
    if(OneToV2!=INT_MAX&&v1ToV2!=INT_MAX&&NTOV1!=INT_MAX) ans=min(ans,OneToV2+v1ToV2+NTOV1);
    cout<<ans;
    return 0;
}
Pr dikj(int s,int e1,int e2){
    vector<int> dis(N+1,INT_MAX);
    dis[s]=0;
    priority_queue<Pr,vector<Pr>,greater<Pr> > pq;
    pq.push({0,s});
    while(!pq.empty()){
        auto[curDis,pos]=pq.top();
        pq.pop();
        for(auto it:mapp[pos]){
            auto[cost,nPos]=it;
            int nDis=cost+curDis;
            if(nDis>=dis[nPos]) continue;
            dis[nPos]=nDis;
            pq.push({nDis,nPos});
        }
    }
    return {dis[e1],dis[e2]};
}

