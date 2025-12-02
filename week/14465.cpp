#include<iostream>
using namespace std;

int N,K,B;
bool isFix[100001]={0};
int main(){
    cin>>N>>K>>B;
    for(int i=0;i<B;i++){
        int tmp;
        cin>>tmp;
        isFix[tmp]=true;
    }
    int cnt=0;
    for(int i=1;i<=K;i++){
        if(isFix[i]) cnt++;
    }
    int minF=cnt;
    for(int i=2;i<=N-K+1;i++){
        if(isFix[i-1]) cnt--;
        if(isFix[i+K-1]) cnt++;
        minF=min(cnt,minF);
    }
    cout<<minF;
    return 0;
}