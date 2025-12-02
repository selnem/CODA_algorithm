#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N,Q;
    vector<int> V;
    vector<int> XOR;
    vector<int> res;
    cin>>N>>Q;
    V.resize(N+1);
    XOR.resize(N+1);
    for(int i=1;i<=N;i++) cin>>V[i];

    XOR[0]=0;
    XOR[1]=V[1];
    for(int i=2;i<=N;i++){
        XOR[i]=XOR[i-1]^V[i];
    }
    for(int i=0;i<Q;i++){
        int a,b;
        cin>>a>>b;
        res.push_back(XOR[b]^XOR[a-1]);
    }
    int ans=0;
    for(int i=0;i<Q;i++){
        ans=ans^res[i];
    }
    cout<<ans;
    return 0;
}