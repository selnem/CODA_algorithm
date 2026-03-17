#include<iostream>
#include<queue>
#include<vector>
using namespace std;


int main(){
    int n;
    int maxScore = -1;
    cin>>n;
    for(int i=0;i<n;i++){
        priority_queue<int, std::vector<int>, std::greater<int>> pq;
        int tmp=0;
        int run1,run2;
        cin>>run1>>run2;
        tmp = max(run1,run2);
        for(int i=0;i<5;i++){
            int tmp2;
            cin>>tmp2;
            pq.push(tmp2);
        }
        tmp+=pq.top();
        pq.pop();
        tmp+=pq.top();
        pq.pop();
        maxScore=max(maxScore,tmp);
    
    }
    cout<<maxScore;

    return 0;
}