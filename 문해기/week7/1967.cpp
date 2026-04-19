#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int,int> pp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<vector<pp>> grp(10001);
    for(int i=0;i<n-1;i++){
        int u,v,d;
        cin>>u>>v>>d;
        grp[u].push_back({v,d});
        grp[v].push_back({u,d});
    }


    
    queue<pp> q;
    int ans=0;

    for(int i=1;i<=n;i++){
        vector<bool> vis(n+1,false);
        q.push({i,0});
        while(!q.empty()){
            pp u=q.front();
            q.pop();
            vis[u.first]=true;
            for(pp it:grp[u.first]){
                if(vis[it.first]) continue;
                int dis=u.second+it.second;
                ans=max(ans,dis);
                q.push({it.first,dis}); 
            }
        }
    }
    
    cout<<ans;

}