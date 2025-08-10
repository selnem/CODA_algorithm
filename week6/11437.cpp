#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    int N;
    int u,v;
    cin>>N;
    vector< vector<int> >Tre(N+1);
    for(int i=0;i<N-1;i++){
        cin>>u>>v;
        Tre[u].push_back(v);
        Tre[v].push_back(u);
    }
    vector<int> parent(N+1,0);
    vector<int> d(N+1,0);
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
    
}