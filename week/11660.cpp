#include<iostream>
using namespace std;

int mapp[1025][1025]={0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N,M,tmp;
    cin>>N>>M;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>tmp;
            mapp[i][j]=mapp[i-1][j]+mapp[i][j-1]+tmp-mapp[i-1][j-1];
        }
    }
    int x1,y1,x2,y2;
    for(int i=0;i<M;i++){
        cin>>x1>>y1>>x2>>y2;
        cout<<mapp[x2][y2]-mapp[x1-1][y2]-mapp[x2][y1-1]+mapp[x1-1][y1-1]<<'\n';
    
    }
    return 0;
}