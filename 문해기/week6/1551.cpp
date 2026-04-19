#include<iostream>
#include<sstream>
#include<queue>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr;
    string line,tmpLine;
    cin>>line;
    stringstream ss(line);

    while (getline(ss, tmpLine, ',')) {
        arr.push_back(stoi(tmpLine)); // 문자열을 int로 변환하여 저장
    }
    for(int i=1;i<=k;i++){
        vector<int> tmp;
        for(int j=0;j<arr.size()-1;j++){
            tmp.push_back(arr[j+1]-arr[j]);
        }
        arr.clear();
        arr=tmp;
        
    }
    for(int i=0;i<arr.size()-1;i++){
        cout<<arr[i]<<',';
    }
    cout<<arr[n-k-1];
    return 0;
}
