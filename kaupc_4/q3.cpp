#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
using namespace std;
int N,M,K;
vector<string> vocbs;
set<string> shorts;
vector<string> ans;
int arr[10]={0};
void makeshort();
void recur(int d,int cnt);

int main(){
    cin>>N>>M>>K;
    for(int i=0;i<N;i++){
        string tmp;
        cin>>tmp;
        vocbs.push_back(tmp);
    }
    recur(0,0);
    if(shorts.size()<K){
        cout<<-1;
        return 0;
    }
    for(string k:shorts){
        ans.push_back(k);
    }
    cout<<ans[K-1];
    return 0;

}
void recur(int d,int cnt){
    if(cnt==M&&d>=N){
        makeshort();
        return;
    }
    if(d>=N) return;
    for(int i=0;i<3;i++){
        arr[d]=i; 
        recur(d+1,cnt+i);
    }
}
void makeshort(){
    string tmp;
    for(int i=0;i<N;i++){
        switch(arr[i]){
            case 0:
                break;
            case 1:
                tmp.push_back(vocbs[i][0]-32);
                break;
            case 2:
                tmp.push_back(vocbs[i][0]-32);
                tmp.push_back(vocbs[i][1]-32);
                break;
        }
    }
    shorts.insert(tmp);
}
