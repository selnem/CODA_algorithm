#include<iostream>
#include<queue>
#include<vector>
#include<climits>
#include<algorithm>
#define INF 1e9+7
using namespace std;

struct Trav{
    int dis;
    int pos;
    int cost;
};

int dis[101];
int cost[101];
vector<Trav> mapp[101];

void ans();
int dijk(int N,int M);

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
    for(int i=0;i<=100;i++){
        mapp[i].clear();
    }
    for(int i=0;i<K;i++){
        int u,v,c,d;
        cin>>u>>v>>c>>d;
        mapp[u].push_back({d,v,c});
    }
    for(int i=0;i<=N;i++){
        sort(mapp[i].begin(), mapp[i].end(), [](const Trav &a, const Trav &b){
            return a.cost < b.cost;  // 비용 순으로 정렬
        });
    }
    int ans=dijk(N,M);
    if(ans==INF) cout<<"Poor KCM"<<'\n';
    
    else cout<<ans<<'\n';
}

int dijk(int N,int M){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(int i = 0; i <= 100; i++) {
        dis[i] = INF;
        cost[i] = INF;
    }
    dis[1] = 0;
    cost[1] = 0;
    pq.push({0, 1});
    while(!pq.empty()){
        int now_time = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        if(dis[now] < now_time) continue;
        if(now == N) continue;
        
        for(auto &delta : mapp[now]){
            int nPos = delta.pos;
            int nCost = delta.cost + cost[now];
            int nDis = delta.dis + now_time;
            
            if(nCost > M) continue;
            
            if(dis[nPos] > nDis && cost[nPos] <= nCost) {
                dis[nPos] = nDis;
                cost[nPos] = nCost;
                pq.push({nDis, nPos});
            }
        }
    }
    return dis[N];
}
