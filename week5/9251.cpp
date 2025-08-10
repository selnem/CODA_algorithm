#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
int dp[1000][1000];
string line1,line2;
int LCS(int idx1,int idx2);
int main(){
    memset(dp,-1,sizeof(dp));
    cin>>line1>>line2;
    cout<<LCS(0,0);
    return 0;
}

int LCS(int idx1,int idx2){

    if(idx1>=line1.length()||idx2>=line2.length()) return 0;

    if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];

    if(line1[idx1]==line2[idx2]) dp[idx1][idx2]=LCS(idx1+1,idx2+1)+1;
    else dp[idx1][idx2]=max(LCS(idx1+1,idx2),LCS(idx1,idx2+1));
    return dp[idx1][idx2];
}