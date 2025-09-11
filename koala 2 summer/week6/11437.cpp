#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void BFS(vector<vector<int> > &T,vector<int> &parent,vector<int> &d,int size);
int LCA(int u,int v,vector<int>&d,vector<int>&p);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N,M;
    int u,v;
    cin>>N;
    vector< vector<int> >Tre(N+1);
    for(int i=0;i<N-1;i++){
        cin>>u>>v;
        Tre[u].push_back(v);
        Tre[v].push_back(u);
    }
    cin>>M;
    vector<int> parent(N+1,0);
    vector<int> d(N+1,0);
    BFS(Tre,parent,d,N);
    for(int i=0;i<M;i++){
        cin>>u>>v;
        cout<<LCA(u,v,d,parent)<<'\n';
    }
    return 0;
}
void BFS(vector<vector<int> > &T,vector<int> &parent,vector<int> &d,int size){
    vector<bool> vis(size+1,false);
    queue<int> q;
    vis[1]=true;
    q.push(1);
    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        for(auto it:T[tmp]){
            if(vis[it]) continue;
            d[it]=d[tmp]+1;
            vis[it]=true;
            parent[it]=tmp;
            q.push(it);
        }
    }

}
int LCA(int u,int v,vector<int>&d,vector<int>&p){
    if(d[u]>d[v]) swap(u,v);
    while(d[u]!=d[v]) v=p[v];
    while(u!=v){
        u=p[u];
        v=p[v];
    }
    return u;
}