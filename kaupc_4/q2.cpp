#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int L;
    vector<int>keys;
    string cyp;
    cin>>cyp;
    cin>>L;
    for(int i=0;i<L;i++){
        int tmp;
        cin>>tmp;
        keys.push_back(tmp);
    }
    for(int i=0; i<cyp.size(); i++){
        cyp[i]=(char)((cyp[i]-'A'+26-keys[i%keys.size()])%26)+'A';
    }
    cout<<cyp;

}