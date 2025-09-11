#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool comp(pair<int,int> &a,pair<int, int> &b);

int main(){
    int N,X;
    int H,L;
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<pair<int,int> > menus;
    int score=0;
    cin>>N>>X;
    for(int i=0;i<N;i++){
        cin>>H>>L;
        menus.push_back(make_pair(H,L));
    }
    sort(menus.begin(),menus.end(),comp);
    X-=1000*N;
    for(auto &it:menus){       
        if(it.first>it.second&&X>=4000){
            score+=it.first;
            X-=4000;
        }
        else{
            score+=it.second;
        };
    }
    cout<<score;
    return 0;

}
bool comp(pair<int,int> &a, pair<int, int> &b){
    int tmp1=abs(a.first-a.second);
    int tmp2=abs(b.first-b.second);
    if(tmp1==tmp2){
        return a.second>b.second;
    }
    return tmp1>tmp2;
}