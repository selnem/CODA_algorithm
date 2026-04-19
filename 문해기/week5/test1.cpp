#include<iostream>
#include<set>
using namespace std;

int L1,L2,K1,K2;
int main(){
    vector<int>l1,l2;
    int ans=0;
    set<int> K[2];
    cin>>L1>>L2;
    cin>>K1>>K2;
    for(int i=0;i<K1+K2;i++){
        int y,x,v;
        cin>>y>>x>>v;
        K[y-1].insert(v);
    }
    for(int it : K[0]){
        if(K[1].find(it)!=K[1].end()){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}