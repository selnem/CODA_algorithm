#include<iostream>
#include<queue>
using namespace std;
int dist[1001][1001]={0};
bool vis[1001][1001]={0};
int main(){
    int s;
    cin>>s;
    

    return 0;
}

int bfs(int s){
    queue< pair<int ,int> > q;
    q.push({1,0});
    vis[1][0]=1;
    while(!q.empty()){
        pair<int, int> tmp=q.front();
        q.pop();
        if(tmp.first!=tmp.second){
            dist[tmp.first][tmp.second]
        }
    }

}