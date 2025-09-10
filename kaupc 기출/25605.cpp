#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

struct Eat{
    int V,H;
};
int DP[101][1000][101];
vector<Eat> meal;
int N,M;
int maxV,delta;
int maxHappy(int cur,int idx,int day);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M;
    int curV;
    cin>>maxV>>delta>>curV;
    for(int i=0;i<N;i++){
        Eat tmp;
        cin>>tmp.V>>tmp.H;
        meal.push_back(tmp);
    }
    memset(DP,-1,sizeof(DP));
    cout<<maxHappy(curV,0,1);
    return 0;
}
int maxHappy(int cur,int idx,int day){
    if(cur<0) cur=0;
    if(day>M) return 0;
    if(idx==N) return 0;
    int &dp=DP[cur][idx][day];
    if(dp!=-1) return dp;
    dp=0;
    dp=max(dp,maxHappy(cur-delta,idx,day+1));
    if(cur+meal[idx].V<=maxV){
        dp=max(dp,maxHappy(cur+meal[idx].V-delta,idx+1,day+1)+meal[idx].H);
    }
    dp=max(dp,maxHappy(cur,idx+1,day));
    return dp;    
}
