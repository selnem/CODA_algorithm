#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
long long cntDiv(int d, int n);
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int c,d,n;
    cin>>c;
    for(int i=0;i<c;i++){
        cin>>d>>n;
        cout<<cntDiv(d,n)<<'\n';
    }
    return 0;
}

long long cntDiv(int d, int n){
    int tmp;
    vector<int> prifix(n+1);
    map<int,long long> cntMap;
    cntMap[0]=1;
    prifix[0]=0;
    long long ans=0;  
    for(int i=1;i<=n;i++){
        cin>>tmp;
        prifix[i]=(prifix[i-1]+tmp)%d;
    }
    for(int i=1;i<=n;i++){
        ans+=cntMap[prifix[i]];
        cntMap[prifix[i]]++;
    }
    return ans;
}