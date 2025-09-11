#include<iostream>
#include<queue>
using namespace std;



int main(){
    int N,M;
    bool vis[100001]={0};
    cin>>N>>M;
    
    if(N>=M){
        cout<<N-M;
        return 0;
    }
    
    queue<pair<int,int>> q;
    q.push({N, 0});
    vis[N] = true;
    
    while(!q.empty()){
        int d = q.front().first;
        int t = q.front().second;
        q.pop();
        
        if(d == M){
            cout << t;
            return 0;
        }
        if(d-1 >= 0 && !vis[d-1]){
            vis[d-1] = true;
            q.push({d-1, t+1});
        }
        if(d+1 <= 100000 && !vis[d+1]){
            vis[d+1] = true;
            q.push({d+1, t+1});
        }
        
        if(d*2 <= 100000 && !vis[d*2]){
            vis[d*2] = true;
            q.push({d*2, t+1});
        }
    }
    
    return 0;
} 