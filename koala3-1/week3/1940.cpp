#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> arr;
    int n;
    int m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        arr.push_back(tmp);
    }

    sort(arr.begin(),arr.end(),less<int>());
    int r=0,l=n-1;
    int ans=0;
    while(r<l){
        int sum=arr[r]+arr[l];
        if(sum==m){
            ans++;
            r++;
            l--;
        }
        else if(sum<m){
            r++;
        }
        else{
            l--;
        }

    }
    cout<<ans;
    return 0;
}