#include<iostream>
#include<vector>
using namespace std;

int rangeSum(vector<int>&arr,pair<int,int>dir);

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N,M,tmp;
    cin>>N>>M;
    vector<int> prifix(N+1,0);
    pair<int, int> dir;
    for(int i=1;i<=N;i++){
        cin>>tmp;
        prifix[i]=prifix[i-1]+tmp;
    }
    for(int i=0;i<M;i++){
        cin>>dir.first>>dir.second;
        cout<<rangeSum(prifix,dir)<<'\n';
    }
    return 0;

}
int rangeSum(vector<int>&arr,pair<int,int>dir){
    return arr[dir.second]-arr[dir.first-1];
}
