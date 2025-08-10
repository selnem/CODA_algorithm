#include<iostream>
#include<vector>
using namespace std;

vector<pair <int,int> > arr(15,make_pair(0,0));
int N;
int dp[15]={0};
int maxCounsel(int d);
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    cout<<maxCounsel(0);

    return 0;
}
int maxCounsel(int d){
    if(d>=N){
        return 0;
    }
    if(dp[d]==0){
        int Cns1=maxCounsel(d+1);
        int Cns2=0;
        if(d+arr[d].first<=N){
            Cns2=maxCounsel(d+arr[d].first)+arr[d].second;
        }
        
        dp[d]=max(Cns1,Cns2);
    }
    return dp[d];
}