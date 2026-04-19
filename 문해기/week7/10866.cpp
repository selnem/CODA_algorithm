#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int q;
    cin>>q;
    vector<int> arr(n+1);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    

    int sqSize=(int)sqrt(n);
    if(sqSize*sqSize<n) sqSize++;

    vector<int> sqArr(sqSize+1,INT_MAX);
    for(int i=0; i < n; i++){
        sqArr[i/sqSize]=min(sqArr[i/sqSize],arr[i]);
    }
    for(int i=0;i<q;i++){
        int s,e;
        cin>>s>>e;
        s--; e--;
        int mVal=INT_MAX;
        int sBlock=s/sqSize;
        int eBlock=e/sqSize;
        if(sBlock==eBlock){
            for(int j=s;j<=e;j++){
                mVal=min(mVal,arr[j]);
            }
            cout<<mVal<<'\n';
            continue;
        }
        for(int j = s; j < (sBlock+1)*sqSize; j++){
            mVal= min(mVal,arr[j]);
        }
        for(int j=sBlock+1; j<eBlock;j++){
            mVal=min(mVal,sqArr[j]);
        }
        for(int j = eBlock*sqSize; j<=e; j++){
            mVal= min(mVal,arr[j]);
        }
        cout<<mVal<<'\n';
    }
    return 0;

}