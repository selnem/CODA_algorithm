#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int cnt=0;
int dist[100001]={0};

vector<vector<int> > grp(100001);

int N,M,start;
void DFS(int s);
int main(){
    cin>>N>>M>>start;
    for(int i=0;i<M;i++){
        int t,k;
        cin>>t>>k;
        grp[t].push_back(k);
        grp[k].push_back(t);
    }
    for(int i=1;i<=N;i++){
        sort(grp[i].begin(),grp[i].end(),greater<int>());
    }
    DFS(start);
    for(int i=1;i<=N;i++){
        cout<<dist[i]<<'\n';
    }
    return 0;
}

void DFS(int s){
    cnt++;
    dist[s]=cnt;
    for(auto k:grp[s]){
        if(dist[k]) continue;
        DFS(k);
    }
}

