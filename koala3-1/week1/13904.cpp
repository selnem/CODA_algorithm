#include<iostream>
#include<queue>
#include<vector>
using namespace std;

typedef pair<int,int> PR;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int sum=0;
   
    priority_queue< PR > pq;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int d,w;
        cin>>d>>w;
        pq.push({d,w});
    }
    int cnt = pq.top().first;
    while(cnt){
        PR tmp = pq.top();
        if(cnt<=tmp.first){
            sum+=tmp.second;
            pq.pop();
            cnt--;
        } 
        else{
            while(cnt=>pq.top())
        }
        
        
   
    }
    cout<<sum;

}