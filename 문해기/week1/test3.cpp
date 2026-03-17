#include<iostream>
using namespace std;

int main(){
    int n;
    int maxSum = -1;
    int scoreA,scoreB,scoreC;
    cin>>scoreA>>scoreB>>scoreC;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp=0;
        for(int i=0;i<3;i++){
            int a,b,c;
            cin>>a>>b>>c;
            temp+=a*scoreA+b*scoreB+c*scoreC;
        }
        maxSum=max(temp,maxSum);
    }
    cout<<maxSum;

    return 0;
}