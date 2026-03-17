#include<iostream>
#include<string.h>
using namespace std;

int dp[1000];
int stap(int n);

int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    cout<<stap(n);
    return 0;
}
int stap(int n){
    int &num = dp[n];
    if( n <= 0 ) return 0;
    if(n ==1 || n == 2) return n;
    if(num != -1) return num;
    num = stap(n - 1) + stap(n - 2);
    return num; 
}