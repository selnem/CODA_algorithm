#include<iostream>
#include<map>
#include<string>
#include<string.h>
using namespace std;

bool vis[100001];
int memo[100001]={0};
int f_fun(int n);
int g_fun(int n,int cmp);
int mul_fun(int x);
int add_fun(int x);
int sol(int L,int R);
int main(){
    int L,R;
    cin>>L>>R;
    cout<<sol(L,R);
    return 0;
}
int add_fun(int x){
    int ans=0;
    while(x){
        ans+=x%10;
        x/=10;
    }
    return ans;
}
int mul_fun(int x){
    int ans=1;
    while(x){
        ans*=x%10;
        x/=10;
    }
    return ans;
}
inline int f_fun(int n){
    return stoi(to_string(add_fun(n))+to_string(mul_fun(n)));
}
int g_fun(int n,int cmp){
    if(vis[n]) return 0;
    if(n>100000) return -1;
    if(n==cmp) return 1;
    if(n==0) return n;
    vis[n]=true;
     g_fun(f_fun(n),cmp);
}
int sol(int L,int R){
    int ans=0;
    for(int i=L;i<=R;i++){
        memset(vis,0,sizeof(vis));
        ans+=g_fun(f_fun(i),i);
    }
    return ans;
}