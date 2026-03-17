#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;

char DP[531444] = {0};
void ans(int n);
void dp(int s,int e);
void prn(int n);
int main(){
    int n;
    while(1){
        cin>>n;
        if(cin.eof()) break;
        ans(n);
    }
    return 0;
}
void dp(int s,int e){
    if(s+1>=e){
        return;
    }
    int b = (e - s + 1)/3;
    for(int i=s+b;i<e-b;i++){
        DP[i] = ' ';
    }
    dp(s,s+b);
    dp(s+b*2,e);
}
void ans(int n){
    memset(DP,'-',sizeof(DP));
    dp(0,(int)pow(3,n));
    prn(n);
}
void prn(int n){
    for(int i=0;i<(int)pow(3,n);i++){
        cout<<DP[i];
    }
    cout<<'\n';
}