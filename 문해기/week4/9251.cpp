#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
int dp[1001][1001];
string line1,line2;
int LCS2(int idx1,int idx2);
int main(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    memset(dp,-1,sizeof(dp));
    cin>>line1>>line2;
    cout<<LCS2(line1.size(),line2.size())<<'\n';
    return 0;
    
}
int LCS2(int idx1,int idx2){
    if(idx1==0||idx2==0) return 0;
    int &DP=dp[idx1][idx2];
    if(DP!=-1) return DP;
    if(line1[idx1-1]==line2[idx2-1]) DP = 1+LCS2(idx1-1,idx2 - 1);
    else DP = max(LCS2(idx1-1,idx2),LCS2(idx1,idx2-1));
    return DP;
}