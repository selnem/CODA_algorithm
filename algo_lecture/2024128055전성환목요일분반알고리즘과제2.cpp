#include<iostream>
#include<vector>
using namespace std;

typedef vector< vector< int> > GRP;
int M,N;

void DFS(int u,GRP &grp,vector<bool> &vis);
bool checkConnected(vector<bool>&vis);

int main(){
    cin>>M>>N;
    GRP grp(M+1); //그래프 배열
    vector<bool>vis(M+1,false);//방문여부 판단 배열
    int startU=1;
    for(int i=0;i<N;i++){

        int u,v;
        cin>>u>>v;

        if(i==0) startU=u;
        grp[u].push_back(v);//무향그래프 이므로 양방향 유향 그래프처럼 삽입
        grp[v].push_back(u);
    }

    DFS(startU,grp,vis);
    cout<<(int)checkConnected(vis);

    return 0;
}

void DFS(int u,GRP &grp,vector<bool> &vis){//dfs 탐색을 통한 시작점에서부터 가능한 모든 노드 탐방
    vis[u]=true;
    for(auto v : grp[u]){//u랑 이어진 간선 v 하나씩
        if(vis[v]) continue; //중복 방문 판단
        DFS(v,grp,vis);//dfs 재귀
    }
    return;
}

bool checkConnected(vector<bool>&vis){
    for(int i=1;i<=M;i++){
        if(!vis[i]) return false;
        //만약 dfs탐색을 통해 연결된 모든 노드를 탐방했음에도 탐방한적 없는 노드가 있다면 연결되어있지 않은 지점이 있으므로
        //연결그래프가 아님
    }
    return true;
}