#include<iostream>
#include<string.h>
using namespace std;
int bunyo(int a,int b);

int DP[15][15];
int main(){
    int t,k,n;
    memset(DP,-1,sizeof(DP));
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>k>>n;
        cout<<bunyo(k,n)<<'\n';
    }

    return 0;
}
int bunyo(int a,int b){
    if(a==0){
        return b;
    }
    int &dp = DP[a][b];
    if(dp != -1) return dp;
    dp=0;
    for(int i=1;i<=b;i++){
        dp+=bunyo(a-1,i);
    }
    return dp;
}