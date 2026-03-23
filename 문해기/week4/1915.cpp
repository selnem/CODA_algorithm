#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int mapp[1001][1001];
int DP[1001][1001];


int sqareDP(int r,int c);
inline int getMin(int a,int b,int c);
int main(){
    memset(DP,-1,sizeof(DP));
    int n,m;
    cin>>n>>m;
    char tmp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>tmp;
            mapp[i][j]=tmp-'0';
        }
    }
    sqareDP(n-1,m-1);
    int maxSize=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            maxSize=max(DP[i][j],maxSize);
        }
    }
    cout<<maxSize*maxSize;
    return 0;
}

int sqareDP(int r,int c){
    if(r==0 || c==0) {
        DP[r][c]=mapp[r][c];
        return DP[r][c];
    }
    int &dp = DP[r][c];
    
    if(dp !=- 1) return dp;

    

    dp=getMin(sqareDP(r-1,c-1),sqareDP(r-1,c),sqareDP(r,c-1))+1;
    if(mapp[r][c]==0){
        dp=0;
        return 0;
    }
    return dp;
}
inline int getMin(int a,int b,int c){
    int tmp=min(a,b);
    tmp=min(tmp,c);
    return tmp;
}