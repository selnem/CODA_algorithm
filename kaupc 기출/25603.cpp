#include <iostream>
#include<vector>
using namespace std;

int main(){
    int N,K;
    cin>>N>>K;
    int ans=0;
    vector<int> arr(N);
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    for(int i=0;i<N-K+1;i++){
        int minIdx=i;
        int minVal=arr[i];
        for(int j=i;j<i+K;j++){
            if(arr[j]<minVal){
                minVal=arr[j];
                minIdx=j;
            }
        }
        ans=max(minVal,ans);
        i=minIdx;
    }
    cout<<ans;
    return 0;
}