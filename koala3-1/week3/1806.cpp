#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> arr;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        arr.push_back(tmp);
    }
    int p1=0,p2=0;
    int s=arr[0],len = 1<<30;
    while(p1<=p2 && p2<n){
        if(s<m) s+=arr[++p2];
        else{
            len=min(len,p2-p1+1);
            s-=arr[p1++];
        }
    }
    if(len==1<<30){
        cout<<0;
        return 0;
    }
    cout<<len;
    return 0;
}