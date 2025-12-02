#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int dp[1001];
vector<int> arr;
int N;

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
    int &len=dp[idx];
    if(idx>=N) return 0;
    if(len != -1) return len;
    len=1;
    for(int i=idx+1;i<N;i++){
        if(arr[idx]<arr[i]) len=max(len,DP(i)+1);
    }
    return len;
}
int findMax(){
    int ans=0;
    for(int i=0;i<N;i++){
        ans=max(ans,DP(i));
    }
    return ans;
}
