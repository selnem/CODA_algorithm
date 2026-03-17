#include<iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        arr.push_back(tmp);
    }
    for(int i=0;i<N;i+=2){
        cout<<arr[i+1]<<' '<<arr[i]<<' ';
    }

    return 0;
}
