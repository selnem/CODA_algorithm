#include<iostream>
#include<vector>
#include<algorithm>

#define MaxNum 100
using namespace std;

int r,c,k;
int mapp[101][101]={0};

int Cal2D();
void rowSort(int &maxR,int &maxC);
void colSort(int &maxR,int &maxC);

int main(){
    cin>>r>>c>>k;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            cin>>mapp[i][j];
        }
    }
    cout<<Cal2D();
    return 0;

}
int Cal2D(){
    int tryCnt=0;
    int maxR=3;
    int maxC=3;
    while(tryCnt<=100&&mapp[r][c]!=k){
        if(maxR>=maxC) rowSort(maxR,maxC);
        else colSort(maxR,maxC);
        ++tryCnt;
    }
    return tryCnt<=100 ? tryCnt:-1;
}

void rowSort(int &maxR,int &maxC){  
    
    for(int i=1;i<=maxR;i++){
        int cntArr[101]={0};
        vector<pair <int,int> >tmp;
        int idx=1;
        for(int j=1;j<=maxC;j++) ++cntArr[mapp[i][j]];
        for(int j=1;j<=100;j++){
            if(cntArr[j]) tmp.push_back(make_pair(cntArr[j],j));
        }
        sort(tmp.begin(),tmp.end());
        for(int j=1;j<=maxC;j++) mapp[i][j]=0;
        for(auto &t:tmp){
            if(idx>100) break;
            mapp[i][idx++]=t.second;
            mapp[i][idx++]=t.first;
        }
        maxC=max(maxC,idx-1);
    }
}
void colSort(int &maxR,int &maxC){  
    
    for(int j=1;j<=maxC;j++){
        int cntArr[101]={0};
        vector<pair <int,int> >tmp;
        int idx=1;
        for(int i=1;i<=maxR;i++) ++cntArr[mapp[i][j]];
        for(int i=1;i<=100;i++){
            if(cntArr[i]) tmp.push_back(make_pair(cntArr[i],i));
        }
        sort(tmp.begin(),tmp.end());
        for(int i=1;i<=maxR;i++) mapp[i][j]=0;
        for(auto &t:tmp){
            if(idx>100) break;
            mapp[idx++][j]=t.second;
            mapp[idx++][j]=t.first;
        }
        maxR=max(maxR,idx-1);
    }
}