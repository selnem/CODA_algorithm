#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int N;
vector<int> ans;
int prifix[42]={0};
int suffix[42]={0};
bool isLucky(int num,int idx);
map<pair<int,int> ,bool> dp;
int main(){
    cin>>N;
    const char*prn[2]={"Unlucky","Lucky"};

    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        ans.push_back(tmp);
    }
    for(int i=N;i>0;i--){
        
        suffix[i-1]=ans[i-1]+suffix[i];
    }
    cout<<prn[isLucky(0,0)];
    return 0;
}

bool isLucky(int num,int idx){
    if(dp[{num,idx}] != dp.end()) return dp[{num,idx}];
    if(idx>=N&&num == 7777777) return true;
    if(idx>=N) return false;
    if(num+suffix[idx]<7777777) return false;
    if(num+suffix[idx]==7777777||num-suffix[idx]==7777777) return true;
    if(num-suffix[idx]>7777777) return false;
    bool isLuck = isLucky(num+ans[idx],idx+1);
    if(!isLuck){
        isLuck=isLucky(num-ans[idx],idx+1);
    }
    dp.insert({num,ans},isLuck);
    return isLuck;
}