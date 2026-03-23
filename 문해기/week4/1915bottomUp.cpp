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
    sqareDP(n,m);
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
    for(int i=0;i<c;i++) DP[0][i] = mapp[0][i];
    for(int i=0;i<r;i++) DP[i][0] = mapp[i][0];
    for(int i=1;i<r;i++){
        for(int j=1;j<c;j++){
            if(mapp[i][j]==0){
                DP[i][j]=0;
                continue;
            }
            DP[i][j]=getMin(DP[i-1][j-1],DP[i-1][j],DP[i][j-1])+1;
        }
     }
     return 0;
}
inline int getMin(int a,int b,int c){
    int tmp=min(a,b);
    tmp=min(tmp,c);
    return tmp;
}