#include<iostream>
#include<vector>
#include<map>
using namespace std;

int N,Q;

map< int, vector<int> > tre;

vector<int> instant;

vector<long long> vis(200010,0);

long long DFS(int idx);

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i=1;i<=N;i++){
        int tmp;
        cin>>tmp;
        if(tmp == 0) continue;
        tre[tmp].push_back(i);
    }
    instant.push_back(0);
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        instant.push_back(tmp);
    }
    DFS(1);
    cin>>Q;
    for(int i=0;i<Q;i++){
        int q;
        cin>>q;
        cout<<vis[q]<<'\n';
    }
    return 0;
}
long long DFS(int idx){
    vis[idx]+=instant[idx];
    for(auto ch:tre[idx]){
        vis[idx]+=instant[ch]+DFS(ch);
    }
    return vis[idx];
}