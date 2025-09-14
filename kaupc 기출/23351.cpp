#include<iostream>
#include<vector>
using namespace std;
int N,K,A,B;
int arr[100];
int main(){
    cin>>N>>K>>A>>B;
    for(int i=0;i<N;i++){
        arr[i]=K;
    }
    return 0;
}
int dayOfdie(){
    int cnt=1;
    while(1){
        watering();
        
    }
}
void watering(){
    static int idx=0;
    for(int i=0;i<A;i++){
        arr[(i+idx)%N]+=B;
    }
}
bool dayAfter(){
    for(int i=0;i<N;i++){
        arr[i]--;
        if(arr[i]==0) return true;
    }
    return false;
}