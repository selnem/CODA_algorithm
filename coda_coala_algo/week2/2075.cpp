#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    priority_queue<int,vector<int>,greater<int> > pq;
    int n;
    int tmp;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>tmp;
            pq.push(tmp);
        }
        while(pq.size()>n){
            pq.pop();
        }
    }
    
    cout<<pq.top();
    return 0;
}