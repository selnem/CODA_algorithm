#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int R,C,Q,tmp;
    cin>>R>>C>>Q;
    vector<vector<int> > pri2D(R+1,vector<int>(C+1,0));
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            cin>>tmp;
            pri2D[i][j]=tmp+pri2D[i-1][j]+pri2D[i][j-1]-pri2D[i-1][j-1];

        }   
    }
    while(Q--){
        int r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2;
        cout<<(pri2D[r2][c2]-pri2D[r1-1][c2]-pri2D[r2][c1-1]+pri2D[r1-1][c1-1])/((r2-r1+1)*(c2-c1+1))<<'\n';
    }
    return 0;
}