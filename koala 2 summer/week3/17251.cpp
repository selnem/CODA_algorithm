#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N,tmp;
    int maxStr=-1;
    vector<int> arr;
    vector<int> maxValIdxs;
    cin>>N;

    for(int i=0;i<N;i++){
        cin>>tmp;
        arr.push_back(tmp);
        maxStr=max(tmp,maxStr);
    }
    for(int i=0;i<N;i++){
        if(arr[i]==maxStr){
            maxValIdxs.push_back(i);
        }
    }
    int Lside=maxValIdxs.front();
    int Rside=N-maxValIdxs.back()-1;
    if(Rside==Lside){
        cout<<'X';
    }
    else if(Lside<Rside){
        cout<<'R';
    }
    else{
        cout<<'B';
    }
    return 0;
}