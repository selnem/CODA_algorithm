#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

typedef pair<int,int> pp;
typedef vector<pp> vpp;

int main(){
    int n;
    cin>>n;
    vpp pos;
    for(int i=0;i<n;i++){
        pp tmp;
        cin>>tmp.first>>tmp.second;
        pos.push_back(tmp);
    }
    sort(pos.begin(),pos.end());



}
inline int dist(pp p1, pp p2){
    return pow(p1.first-p2.first,2)+pow(p1.second-p2.second,2);
}

void close(vpp &pos,int n){
    if(n == 1) return 
}

void divider(vpp& pos,int left,int right,int mid){

}