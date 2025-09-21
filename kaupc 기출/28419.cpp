#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long LL;

int N;
LL mincnt(LL&odd,LL&even);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    LL odd=0,even=0;
    for(int i=1;i<=N;i++){
        int tmp;
        cin>>tmp;
        if(i%2){
            odd+=tmp;
        }
        else{
            even+=tmp;
        }
    }
    cout<<mincnt(odd,even);    
    return 0;
}
LL mincnt(LL&odd,LL&even){
    if(N==3){
        if(odd>even){
            return -1;
        }
    }
    return abs(odd-even);
}
