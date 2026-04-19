#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

typedef pair<int,int> PP; // first: 값, second: 인덱스

vector<int> arr;
vector<PP> tre(300000,{INT_MAX,INT_MAX});
int n;

PP init(int s = 0, int e = n-1, int nodeIdx = 1);
PP query(int l,int r,int nodeIdx = 1,int s = 0, int e = n-1);
PP update(int idx,int d,int nodeIdx = 1, int s = 0, int e = n-1);



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        arr.push_back(tmp);
    }
    init();
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int cmd, a, b;
        cin>>cmd>>a>>b;
        switch(cmd){
            case 1:
                update(a-1,b);
                break;
            case 2:
                cout<<query(a-1,b-1).second+1<<'\n';
                break;
            default:
                break;
        }
    }
    return 0;
}

PP init(int s, int e, int nodeIdx){
    if(s==e) return tre[nodeIdx] = {arr[s],s};
    int m = (s+e)/2;
    PP mNode = min(init(s, m, nodeIdx*2), init(m+1, e, nodeIdx*2+1));
    return tre[nodeIdx] = mNode;
}

PP query(int l,int r,int nodeIdx, int s, int e){
    if(l > e || s > r) return {INT_MAX, INT_MAX};
    if(l <= s && e <= r) return tre[nodeIdx];
    int m = (s+e)/2;
    return min(query(l,r,nodeIdx*2,s,m),query(l,r,nodeIdx*2+1,m+1,e));
}

PP update(int idx,int d,int nodeIdx, int s, int e){
    if(idx<s ||idx>e) return tre[nodeIdx];
    if(s==e) return tre[nodeIdx] = {d,idx};
    int m =(s+e)/2;
    tre[nodeIdx] = min(update(idx,d,nodeIdx*2,s,m),update(idx,d,nodeIdx*2+1,m+1,e));
    return tre[nodeIdx];
}
