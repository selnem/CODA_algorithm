#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int dp[2][100000]={0};
int mapp[2][100000]={0};
int n;

int stMax();
int stDP(int r,int c);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);  
    int T;
    cin>>T;

    for(int i=0;i<T;i++){
        cout<<stMax()<<'\n';
    }
    return 0;
}
int stMax(){
    memset(dp,-1,sizeof(dp));

    cin>>n;
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            cin>>mapp[i][j];
        }
    }
    return max(stDP(1,0),stDP(0,0));
}
int stDP(int r,int c){
    if(c>=n){
        return 0;
    }
    if(dp[r][c]!=-1){
        return dp[r][c];
    }
    if(r==1) return dp[r][c]=max(stDP(0,c+1),stDP(0,c+2))+mapp[r][c]; 
    if(r==0) return dp[r][c]=max(stDP(1,c+1),stDP(1,c+2))+mapp[r][c];
    return -1;
}

