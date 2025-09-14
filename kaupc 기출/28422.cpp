#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

inline int score(const int num);
int max_score(int idx);
int N;
vector<int> arr;
int DP[100001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        arr.push_back(tmp);
    }
    memset(DP,-1,sizeof(DP));
    int ans=max_score(0);
    cout<<( (ans<0) ? 0 :ans);
    return 0;
}
inline int score(const int num){
    int score=0;
    for(int i=0;i<=10;i++){
        if((1<<i)&num) score++;
    }
    return score;
}
int max_score(int idx){
    if(idx==(N-1)) return -(1<<30);
    if(idx>=N) return 0;
    int &dp=DP[idx];
    if(dp!=-1) return dp;
    dp=0;
    if(idx<=N-3){
        
        dp=max(dp,score(arr[idx]^arr[idx+1]^arr[idx+2])+max_score(idx+3));
    }
    if(idx<=N-2){
        dp=max(dp,score(arr[idx]^arr[idx+1])+max_score(idx+2));
    }
    return dp;
}
