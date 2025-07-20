#include<iostream>
#include<vector>
using namespace std;
int sum2D(
    const vector< vector<int> >&arr,
    pair<int, int> s,
    pair <int ,int> e);
int main(){
    int N,M,tmp,K;
    cin>>N>>M;
    vector< vector<int> >prifix(N+1,vector<int>(M+1,0));
    pair<int, int> s,e; 
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>tmp;
            prifix[i][j]=tmp+prifix[i-1][j]+prifix[i][j-1]-prifix[i-1][j-1];
        }
    }
    cin>>K;
    for(int i=0;i<K;i++){
        cin>>s.first>>s.second>>e.first>>e.second;
        cout<<sum2D(prifix,s,e)<<'\n';
    }


    return 0;
}
int sum2D(
    const vector< vector<int> >&arr,
    pair<int, int> s,
    pair <int ,int> e){
    int res=arr[e.first][e.second]-arr[e.first][s.second-1]-arr[s.first-1][e.second]+arr[s.first-1][s.second-1];
    return res;
}