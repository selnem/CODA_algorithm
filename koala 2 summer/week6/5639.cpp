#include<iostream>
#include<vector>
using namespace std;

vector<int> arr;
void postOrder(int s,int e);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tmp;
    while(1){
        cin>>tmp;
        if(cin.eof()) break;
        arr.push_back(tmp);
    }
    postOrder(0,arr.size()-1);
    return 0;
}

void postOrder(int s,int e){
    if(s>e) return;
    int m=e+1;

    for(int i=s+1;i<=e;i++){
        if(arr[s]<arr[i]){
            m=i;
            break;
        }
    }
    postOrder(s+1,m-1);
    postOrder(m,e);
    cout<<arr[s]<<'\n';
}
