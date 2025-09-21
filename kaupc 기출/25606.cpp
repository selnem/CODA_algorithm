#include<iostream>
#include<vector>
using namespace std;

int N,M,Q;
int Rain[100001]={0};
int Dry[100001]={0};
int BoxStat[2][100001]={0};
void Ans1();
void Ans2();
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M>>Q;
    int boxCnt=0;
    for(int i=1;i<=N;i++){
        int tmp;
        cin>>tmp;
        Rain[i]=Rain[i-1]+tmp;
        Dry[i]=Dry[i-1];
        if(BoxStat[0][i]>0){
            boxCnt-=BoxStat[0][i];
            Dry[i]+=BoxStat[1][i];
        }
        Dry[i]+=M*boxCnt;
        int endDay=i+(tmp/M)+1;
        if(endDay<=N){
            BoxStat[0][endDay]++;
            BoxStat[1][endDay]+=tmp%M;
        }
        boxCnt++;
    }
    for(int i=0;i<Q;i++){
        int qType;
        cin>>qType;
        switch(qType){
            case 1:
                Ans1();
                break;
            case 2:
                Ans2();
                break;
            default:
                cout<<"error"<<'\n';
                break;
        }
    }

    return 0;
}
void Ans1(){
    int val;
    cin>>val;
    cout<<Rain[val]-Dry[val]<<'\n';
}
void Ans2(){
    int val;
    cin>>val;
    cout<<Dry[val]-Dry[val-1]<<'\n';
}