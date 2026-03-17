#include<iostream>
#include<vector>
using namespace std;

vector<int> ans;
void fn(int n);
int main(){
    int n;
    cin>>n;
    fn(n);
    for(auto it:ans){
        cout<<it<<' ';
    }
    return 0;
}
void fn(int n){
    ans.push_back(1);
    for(int i=2;i<=n;i++){
        int s=ans.size();
        ans.push_back(i);
        for(int j=0;j<s;j++){
            ans.push_back(ans[j]);
        }
    }
    return;
}