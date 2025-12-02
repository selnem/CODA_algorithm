#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector <int> arr;
    int N,M;
    int ans=0;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        arr.push_back(tmp);
    }
    for(int i=arr.size()-1;i>=0;i--){
        if(arr[i]>M) continue;
        ans+=M/arr[i];
        M%=arr[i];
    }
    cout<<ans;
    return 0;
}