#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N,M;
    int cnt=0;
    cin>>N>>M;
    vector<int> arr(N+1);
    for(int i=0;i<N;i++) cin>>arr[i];
    int s=0,e=0;
    int res=arr[0];
    while(s<=e&&e<N){
        if(res<M) res+=arr[++e];
        else if(res==M){
            cnt++;
            res+=arr[++e];
        }
        else if(res>M) {
            res-=arr[s++];
            if (s>e){
                e=s;
                res=arr[s];
            }
        }
    }
    cout<<cnt;
    return 0;
}