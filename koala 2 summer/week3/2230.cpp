#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N,M,tmp;
    vector<int>arr;
    int ans=0x7FFFFFFF;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(),arr.end());
    int s=0,e=1;
    while(s<N&&e<N){
        int res=arr[e]-arr[s];
        if(res<M){
            e++;
        }
        else{
            ans=min(ans,res);
            s++;
        }
    }
    cout<<ans;
    return 0;
}