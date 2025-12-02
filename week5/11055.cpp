#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int dp[10001];
int N;
vector<int> arr;
int findMax();
int DP(int idx);
int main(){

    memset(dp,-1,sizeof(dp));

    cin>>N;
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        arr.push_back(tmp);
    }
    cout<<findMax();

    return 0;
}
int DP(int idx){

    int &ret=dp[idx];
    if(idx==N) return 0;
    if(ret != -1 ) return ret;

    ret=arr[idx];
    for(int i=idx+1;i<N;i++){
        if(arr[idx]<arr[i]) ret=max(ret,DP(i)+arr[idx]);
    }
    return ret;
}
int findMax(){
    int ans=-1;
    for(int i=0;i<N;i++){
        ans=max(ans,DP(i));
    }
    return ans;
}