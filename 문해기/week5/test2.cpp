#include<iostream>
using namespace std;


int prifix[301][301]={0};
int n,m,k;
inline int getSum(int x1, int y1, int x2, int y2);

int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int tmp;
            cin>>tmp;
            prifix[i][j]=tmp+prifix[i][j-1]+prifix[i-1][j]-prifix[i-1][j-1];
        }
    }
    for(int i=0;i<k;i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<getSum(x1,y1,x2,y2)<<'\n';
    }
    return 0;
}
inline int getSum(int x1, int y1, int x2, int y2){
    return prifix[x2][y2]-prifix[x1-1][y2]-prifix[x2][y1-1]+prifix[x1-1][y1-1];
}