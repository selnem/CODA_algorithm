#include<iostream>
using namespace std;

int prifix[301][301]={0};
int N,M;
int a,b,c;


int ans();

inline bool inRange1(int i,int j);
inline bool inRange2(int i,int j);
inline bool inRange3(int i,int j);
int pos1(int i,int j);
int pos2(int i,int j);
int pos3(int i,int j);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tmp;
    cin>>N>>M;
    cin>>a>>b>>c;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>tmp;
            prifix[i][j]=tmp+prifix[i][j-1]+prifix[i-1][j]-prifix[i-1][j-1];
        }
    }
    cout<<ans();
    return 0;
}
int pos1(int i,int j){
    if(!inRange1(i,j)) return 0;
    int r1=i+a-1;
    int c1=j+b+c-1;
    return prifix[r1][c1]-prifix[r1][j-1]-prifix[i-1][c1]+prifix[i-1][j-1];
}
inline bool inRange1(int i,int j){
    return 1<=i&&i+a-1<=N&&1<=j&&j+b+c-1<=M;
}
int pos2(int i,int j){
    if(!inRange2(i,j)) return 0;
    int r1=i+a-1;
    int c1=j+c-1;
    int r2=r1+b;
    int c2=c1+a;
    int box1=prifix[r1][c1]-prifix[r1][j-1]-prifix[i-1][c1]+prifix[i-1][j-1];
    int box2=prifix[r2][c2]-prifix[r2][c1]-prifix[r1][c2]+prifix[r1][c1];
    return box1+box2;
}
inline bool inRange2(int i,int j){
    return 1<=i&&i+a+b-1<=N&&1<=j&&j+c+a-1<=M;
}
int pos3(int i,int j){
    if(!inRange3(i,j)) return 0;
    int r1=i+a-1;
    int c1=j+b-1;
    int r2=r1+c;
    int c2=c1+a;
    int box1=prifix[r1][c1]-prifix[r1][j-1]-prifix[i-1][c1]+prifix[i-1][j-1];
    int box2=prifix[r2][c2]-prifix[r2][c1]-prifix[r1][c2]+prifix[r1][c1];
    return box1+box2;
}
inline bool inRange3(int i,int j){
    return 1<=i&&i+a+c-1<=N&&1<=j&&j+a+b-1<=M;
}
int ans(){
    int (*fp[3])(int,int);
    fp[0]=pos1;
    fp[1]=pos2;
    fp[2]=pos3;
    int ans=1<<30;
    for(int t=0;t<3;t++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                int tmp=fp[t](i,j);
                if(tmp) ans=min(ans,tmp);
            }
        }
    }
    return ans;
}