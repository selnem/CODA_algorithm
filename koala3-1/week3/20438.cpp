#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

unordered_set<int> absense;
inline bool isAbsens(int tmp);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n ,k, q, m;
    cin>>n>>k>>q>>m;
    queue<int> attend;
    vector<int> arr(n+3,1);

    for(int i=0;i<k;i++){
        int tmp;
        cin>>tmp;
        absense.insert(tmp);
    }
    for(int i=0;i<q;i++){
        int tmp;
        cin>>tmp;
        if(isAbsens(tmp)) continue;
        attend.push(tmp);
    }

    arr[0]=arr[1]=arr[2]=0;

    while(!attend.empty()){
        int t =attend.front();
        attend.pop();

        for(int i= t ;i<=n+2;i += t){
            if(isAbsens(i)) continue;
            arr[i]=0;
        }
    }
    for(int i=3;i<=n+2;i++) arr[i]+=arr[i-1];
    for(int i=0;i<m;i++){
        int s,e;
        cin>>s>>e;
        cout<<arr[e]-arr[s-1]<<'\n';
    }
    return 0;

}
inline bool isAbsens(int tmp){
    return absense.find(tmp)!=absense.end();
}